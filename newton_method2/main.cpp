#include <iostream>
#include <math.h>

template <typename T> T new_x(T num, T x)
{
    T func = x * x -num;
    T func_der = 2 * x;
   
    return x - func / func_der;
}

template <typename Q> Q sqrt_newton(Q num, Q x0)
{
    double stop = 1E-5;
    Q x1;
    do
    {
        x1 = x0;
        x0 = new_x<Q>(num, x0);
    }while(std::abs(x1 - x0) >= stop);
    
    return x1;
}


int main()
{
    std::cout.precision(16);
    
    std::cout << sqrt_newton<double>(52, 4) << std::endl;

    return 0;
}