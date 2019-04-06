#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <initializer_list>
#include <cmath>
#include <ostream>
#include <iostream>

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
                h += m1.data[N * i + k] * m2.data[N * k + j];
            }  
			hold[j] = h;          
        } 

		for(int l=0; l < N; l++)  //átmeneti vektor elemeinek átadása
		{
			m3.data[N * i + l] = hold[l];
			hold[l]=0;
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
        data;
        data.resize(N * N);
    }

	matrix(int N, std::vector<T> m): dim{N}, data{m}
    {
    }

	matrix(matrix const& cpy): dim{cpy.dim}, data{cpy.data}
    {
    }

	matrix<T>& operator= (matrix const&) = default;

    
   	T&       operator()(int i, int j) { return data[i * dim + j]; }    //indexelés
	T const& operator()(int i, int j) const{ return data[i * dim + j]; }



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
        	detail::transform_vector1((*this).data, (*this).data, [](T const& x){ a*x ;});
        	return *this;
    	}

    	matrix<T>& operator /= (T const& a)
    	{
        	detail::transform_vector1((*this).data, (*this).data, [](T const& x){ x/a ;});
        	return *this;
    	}

		

	
};

