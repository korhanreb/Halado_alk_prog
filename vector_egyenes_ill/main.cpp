#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

double average_vec(std::vector<double> const& v)
{
    int n = static_cast<int>(v.size());
    double a= accumulate( v.begin(), v.end(), 0.0)/n;
    return a;
}


double product(std::vector<double> const& a, std::vector<double> const& b)
{
    double av_a= average_vec(a);
    double av_b= average_vec(b);

    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0, [](double a, double b)->double {return a+b;}, [av_a, av_b](double a, double b)-> double {return (a-av_a)*(b-av_b); });
}


double av_product(std::vector<double> const& a, std::vector<double> const& b)
{
    double av_a= average_vec(a)*average_vec(a);
    double av_b= average_vec(b)*average_vec(b);
    int n = static_cast<int>(a.size());

    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0)/n;
}





int main() {
    std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<double> Y = {3.1, 5.5, 6.8, 8.90, 11.2, 13.0, 15.0};

    double XY=product(X, Y);
    double X_sqsum =product(X,X);
    std::array<double, 2> sol = {XY/X_sqsum, average_vec(Y)-average_vec(X)*XY/X_sqsum};

    std::cout << "m = " << sol[0] <<std::endl;
    std::cout << "b = " << sol[1] <<std::endl;   

    //r^2

    double sq_r = (av_product(X,Y)-average_vec(Y)*average_vec(X))*(av_product(X,Y)-average_vec(Y)*average_vec(X))/
                  ((av_product(X,X)-average_vec(X)*average_vec(X))*(av_product(Y,Y)-average_vec(Y)*average_vec(Y)));
    
    std::cout << "sq_r = " << sq_r <<std::endl;               

    return 0;
}
