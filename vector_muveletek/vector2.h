#include <iostream>

template<typename T>
struct Vector2d
{
	T x, y;

	template<typename T2>
	Vector2d<T>& operator+=( Vector2d<T2> const& v )
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	template<typename T2>
    Vector2d<T>& operator-=( Vector2d<T2> const& v )
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	template<typename T3>
    Vector2d& operator*=(T3 const& a)
	{
		x *=a;
		y *=a;
		return *this;
	}

	template<typename T3>
	Vector2d& operator/=(T3 const& a)
	{
		x /=a;
		y /=a;
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
	using T4 = decltype(a*v.x);
	return Vector2d<T4>{ a*v.x , a*v.y};
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
	using T3 = decltype(v/ length(v));
	return v/ length(v);
}


template<typename T>
std::ostream& operator<<(std::ostream& o, Vector2d<T> const& v)
{
    o << '[' << v.x << ',' << v.y << ']';
    return o; 
}

template<typename T>
std::istream& operator>>(std::istream& i, Vector2d<T>& v)
{
    i >> v.x;
    i >> v.y;
    return i; 
}
