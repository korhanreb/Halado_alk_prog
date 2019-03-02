#include <iostream>
#include <cmath>

double func(double x)
{
    return cos(x) * std::exp(-x * x);
}

double integrate(int n, double x0, double x1)
{
    double sum = 0.0;
    double h = (x1 - x0) / n; // ahol x1>x0
    //if ( x1 > x0 ){double h = (x1 - x0) / n;} --valamiért nem működik
    //else {double h = (-x1 + x0) / n;}
    
    for(int i = 0; i <= n ; i++)
    {
        sum += func(x0 + i * h);
    }

    return h * sum;
}

void test(int j, int d,  double x0, double x1) // hányszor, milyen lépésközzel, integrate fgv. határai
{
    double I=1.34638795680345037669816;
    for(int i=1; i<j; ++i)
    {
        std::cout <<integrate(i*d, x0, x1)-I << std::endl;
    }
}

int main()
{
    std::cout.precision(16);

    std::cout <<integrate(10, -1 , 3) << std::endl;
    test(20, 20,  -1, 3);
    return 0;
}

