#include <iostream>
#include <cmath>

double new_x(double num, double x)
{
    double func = x * x -num;
    double func_der = 2 * x;
   
    return x - func / func_der;
}

double sqrt_newton(double num, double x0)
{
    double stop = 1E-5;
    double x1;
    do
    {
        x1 = x0;
        x0 = new_x(num, x0);
    }while(std::abs(x1 - x0) >= stop);
    
    return x1;
}


int main()
{
    std::cout.precision(16);
    
    std::cout << sqrt_newton(52, 4) << std::endl;

    return 0;
}

