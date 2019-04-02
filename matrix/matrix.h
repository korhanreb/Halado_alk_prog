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

//Common lambdas:
inline auto add = [](auto const& x, auto const& y){ return x + y; };
inline auto sub = [](auto const& x, auto const& y){ return x - y; };

template<typename T>
class matrix
{
	public:
   		int dim;
		std:: vector<T> data;


    	T&       operator()(int i, int j) { return data[i * dim + j]; }    //indexelés
		T const& operator()(int i, int j) const{ return data[i * dim + j]; }



		matrix<T>& operator += (matrix<T> const& m)
    	{
        	detail::transform_vector1((*this).data, (*this).data, m.data, add);
       		return *this;
    	}

		matrix<T>& operator -= (matrix<T> const& m)
    	{
        	detail::transform_vector1((*this).data, (*this).data, m.data, sub);
        	return *this;
    	}
	
};

