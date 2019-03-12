#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<double> average_vec(std::vector<double> const& v)
{
    int n = static_cast<int>(v.size());
    double a= accumulate( v.begin(), v.end(), 0.0)/n;
    std::vector<double> k = v;
    fill(k.begin(), k.end(), -1*a);
    return k;
}

std::vector<double>  transformed(std::vector<double> const& v)
{
    std::vector<double> n = v;
    std::transform( n.begin(), n.end(), average_vec(v), n, std::plus<double>()) ;
    return n;
}


double func_sq_sum (double a, double b)
    { 
        return a + b*b;
    }

double product(std::vector<double> const& a, std::vector<double> const& b)
    {
    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    }





int main() {
    std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<double> Y = {3.2, 4.9, 7.3, 8.7, 11.5, 12.6, 15.4};

    std::vector<double> av_X=average_vec(X);
    std::vector<double> av_Y=average_vec(Y);
    std::vector<double> tr_X=transformed(X);
    std::vector<double> tr_Y=transformed(Y);

    double XY=product(tr_X, tr_Y);
    double X_sqsum =accumulate(X.begin(), X.end(), 0, func_sq_sum );

    std::array<int, 2> sol = {XY/X_sqsum, av_Y[0]-av_X[0]*XY/X_sqsum};

    std::cout << "m = " << sol[0] <<std::endl;
    std::cout << "b = " << sol[1] <<std::endl;    

}
