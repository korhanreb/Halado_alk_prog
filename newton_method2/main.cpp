#include <iostream>
#include <cmath>

template <typename T, typename Q1, typename Q2>
T Newton(Q1 func, Q2 func_der, T x0)
{
    T x1;
    int n = 0;
    double stop = 1E-5;
    do
    {
        x1 = x0;
        x0 = x0 - func(x0) / func_der(x0);

        n++;
    }while(std::abs(x1 - x0) >= stop || n==20);

    return x0;
}


int main()
{
    std::cout.precision(16);    

    std::cout << Newton<double>([](double x){ return x*x - 612.0; }, [](double x){ return 2.0*x; }, 10.0) << std::endl;
    

    return 0;
}