#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

template<typename T>
struct Vector2d
{
	T x, y;

	template<typename T2>
	Vector2d<T>& operator+=( Vector2d<T2> const& v )
	{
		x = static_cast<T>(x + v.x);;
		y = static_cast<T>(y + v.y);
		return *this;
	}

	template<typename T2>
    Vector2d<T>& operator-=( Vector2d<T2> const& v )
	{
		x = static_cast<T>(x - v.x);
		y = static_cast<T>(y - v.y);
		return *this;
	}

	template<typename T3>
    Vector2d& operator*=(T3 const& a)
	{
		x = static_cast<T>(a*x);
		y = static_cast<T>(a*y);
		return *this;
	}

	template<typename T3>
	Vector2d& operator/=(T3 const& a)
	{
		x = static_cast<T>(x/a);
		y = static_cast<T>(y/a);
		return *this;
	}
};

template<typename T, typename T2>
auto operator+( Vector2d<T> const& v, Vector2d<T2> const& u )
{
	using T3 = decltype(v.x+u.x);
	return Vector2d<T3>{ v.x + u.x, v.y + u.y };
}

template<typename T, typename T2>
auto operator-( Vector2d<T> const& v, Vector2d<T2> const& u )
{
	using T3 = decltype(v.x-u.x);
	return Vector2d<T3>{ v.x - u.x, v.y - u.y };
}


template<typename T, typename T3>
auto operator*(T3 const& a , Vector2d<T> const& v)
{
	using T4 = decltype(a*v.x);
	return Vector2d<T4>{ a*v.x , a*v.y};
}

template<typename T, typename T3>
auto operator*(Vector2d<T> const& v, T3 const& a )
{
	using T4 = decltype(v.x*a);
	return Vector2d<T4>{ v.x*a , v.y*a};
}

template<typename T, typename T3>
auto operator/(Vector2d<T> const& v, T3 const& a )
{
	using T4 = decltype(v.x/a);
	return Vector2d<T4> { v.x/a , v.y/a };
}

template<typename T, typename T2>
auto dot( Vector2d<T> const& v, Vector2d<T2> const& u )
{
	return u.x*v.x + u.y*v.y;
}

template<typename T>
auto sqlength(Vector2d<T> const& v)
{
	return v.x*v.x+v.y*v.y;
}

template<typename T>
auto length(Vector2d<T> const& v)
{
	return std::sqrt(v.x*v.x+v.y*v.y);
}

template<typename T>
auto normalize(Vector2d<T> const& v)
{
	return v/ length(v);
}


template<typename T>
std::ostream& operator<<(std::ostream& o, Vector2d<T> const& v)
{
    o  << v.x << ',' << v.y ;
    return o; 
}

template<typename T>
std::istream& operator>>(std::istream& s, Vector2d<T>& v)
{
	const auto state = s.rdstate();  //kezdeti állapot 
	const auto pos = s.tellg();	  //olvasási pozíció
	bool error=false;
	//
	std::vector<T> v1;
	std::string tmp;
	std::getline(s, tmp); //az s-ből az első sort belerakja a tmp-be
	if(tmp.size() > 0)
	{
		T x;
		std::stringstream ss(tmp);   //ss a szóközig a karakterlánc
		while(ss >> x)
		{
			v1.push_back(x);  //belerakjuk a v-be a beolvasott elemet
		}
		v.x=v1[0];
		v.y=v1[1];

		if (!ss.eof() &&( ss.fail() || ss.bad()))
		{
			error=true;
		}
				
		if(!s || error) 
		{
			s.clear();
			s.seekg(pos);
			s.setstate(state);
		}	
	}
	return s; 

}


