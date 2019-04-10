#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <initializer_list>
#include <cmath>
#include <ostream>

namespace detail
{
	template<typename V1, typename V2, typename F>
	void transform_vector1(V1 const& v1, V2& v2, F f)
	{
		std::transform(v1.cbegin(), v1.cend(), v2.begin(), f);
	}

	template<typename V1, typename V2, typename V3, typename F>
	void transform_vector2(V1 const& v1, V2 const& v2, V3& v3, F f)
	{
		std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v3.begin(), f);
	}
}

template <typename T>
auto multiplication_matrix( int N,   std::vector<T> const& m1, std::vector<T> const& m2, std::vector<T> & m3)
{
    std::vector<T> hold;
    hold.resize(N);
	T h;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)  //szorzás elvégzése
        {
            h=0;
            for(int k=0; k < N; k++)
            {
                h += m1[N * i + k] * m2[N * k + j];
            }  
			hold[j] = h;          
        } 

		for(int l=0; l < N; l++)  //átmeneti vektor elemeinek átadása
		{
			m3[N * i + l] = hold[l];
		}  

    } 
    return m3;
} 

//Common lambdas:
inline auto add = [](auto const& x, auto const& y){ return x + y; };
inline auto sub = [](auto const& x, auto const& y){ return x - y; };

template<typename T>
class matrix
{
	int dim;
	std:: vector<T> data;

public:

	matrix()
    {
        dim = 0;
        data;
    }

    matrix(int N)
    {
        dim = N;
        data.resize(N * N);
    }

	matrix(int N, std::vector<T> m): dim{N}, data{m}
    {
    }

	matrix(matrix const& cpy): dim{cpy.dim}, data{cpy.data}
    {
    }

	matrix( matrix<T>&& mv )
	{
		std::swap(dim, mv.dim);
		std::swap(data, mv.data);
	}

	//matrix<T>& operator= (matrix const&) =default;
	matrix<T>& operator=(matrix<T> const& cpy );
	matrix<T>& operator=(matrix<T> && mv );

	//Number of elements of the Vector:
	int size()const
	{
		return static_cast<int>(data.size());
	}

	//begin and end for compatibility with STL:
	auto begin()
	{
		return data.begin();
	}

	auto cbegin() const
	{
		return data.cbegin();
	}

	auto end()
	{
		return data.end();
	}

	auto cend() const
	{
		return data.cend();
	}

	//Indexelés:
	T& operator()(int i, int j) { return data[i * dim + j]; }    
	T const& operator()(int i, int j) const{ return data[i * dim + j]; }
	T& operator[]( int i ) { return data[i]; }
	T const& operator[]( int i ) const { return data[i]; }


		matrix<T>& operator += (matrix<T> const& m)
    	{
        	detail::transform_vector2((*this).data, m.data, (*this).data, add);
       		return *this;
    	}

		matrix<T>& operator -= (matrix<T> const& m)
    	{
        	detail::transform_vector2((*this).data,  m.data, (*this).data, sub);
        	return *this;
    	}

		matrix<T>& operator *= (matrix<T> const& m)
    	{
        	multiplication_matrix((*this).dim, (*this).data, m.data , (*this).data);
        	return *this;
    	}

		matrix<T>& operator *= (T const& a)
    	{
        	detail::transform_vector1((*this).data, (*this).data, [a](T const& x){return a*x ;});
        	return *this;
    	}

    	matrix<T>& operator /= (T const& a)
    	{
        	detail::transform_vector1((*this).data, (*this).data, [a](T const& x){return x/a ;});
        	return *this;
    	}
		//külső hozzáférés adása
		template<typename T2>
		friend matrix<T2> operator+(matrix<T2> const& m1, matrix<T2> const& m2);
		template<typename T2>
		friend matrix<T> operator-(matrix<T2> const& m1, matrix<T2> const& m2);
		template<typename T2>
		friend matrix<T2> operator*(matrix<T2> const& m1, T2 const& a);
		template<typename T2>
		friend matrix<T2> operator/(matrix<T2> const& m1, T2 const& a);
		template<typename T2>
		friend matrix<T2> operator*(matrix<T2> const& m1, matrix<T2> const& m2);

};

// nem beépített műveletek


//összeadás
template<typename T>
matrix<T> operator+(matrix<T> const& m1, matrix<T> const& m2)
{
    matrix<T> result(m1.dim);
    detail::transform_vector2(m1.data, m2.data, result.data, add);
    return result;
}

template<typename T>
matrix<T> operator+(matrix<T> && m1, matrix<T> const& m2)
{
    detail::transform_vector2(m1.data, m2.data, m1.data, add);
    return std::move(m1);
}

template<typename T>
matrix<T> operator+(matrix<T> const& m1, matrix<T> && m2)
{
    detail::transform_vector2(m1.data, m2.data, m2.data, add);
    return std::move(m2);
}

template<typename T>
matrix<T> operator+(matrix<T> && m1, matrix<T> && m2)
{
    detail::transform_vector2(m1.data, m2.data, m1.data, add);
    return std::move(m1);
}

//kivonás
template<typename T>
matrix<T> operator-(matrix<T> const& m1, matrix<T> const& m2)
{
    matrix<T> result(m1.dim);
    detail::transform_vector2(m1.data, m2.data, result.data, sub);
    return result;
}

//skalárral szorzás
template<typename T>
matrix<T> operator*(matrix<T> const& m1, T const& a)
{
    matrix<T> result(m1.dim);
    detail::transform_vector1(m1.data, result.data, [a](T const& x){return a*x ;});
    return result;
}

//skalárral osztás
template<typename T>
matrix<T> operator/(matrix<T> const& m1, T const& a)
{
    matrix<T> result(m1.dim);
    detail::transform_vector1(m1.data,  result.data, [a](T const& x){return x/a ;});
    return result;
}

//mátrix szorzás
template<typename T>
matrix<T> operator*(matrix<T> const& m1, matrix<T> const& m2)
{
    matrix<T> result(m1.dim);
    multiplication_matrix(m1.dim, m1.data, m2.data, result.data);
    return result;
}



