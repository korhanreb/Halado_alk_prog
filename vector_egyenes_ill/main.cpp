#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

double average_vec(std::vector<double> const& v)
{
    int n = static_cast<int>(v.size());
    return accumulate( v.begin(), v.end(), 0.0)/n;
}



std::array<double, 3> illesztes(std::vector<double> const& x, std::vector<double> const& y)
{
    double av_x= average_vec(x);
    double av_y= average_vec(y);
    int n = static_cast<int>(x.size());

    auto product=[av_x, av_y](std::vector<double> const& a, std::vector<double> const& b)->double
    {
        return std::inner_product(a.begin(), a.end(), b.begin(), 0.0, [](double a, double b)->double {return a+b;}, [av_x, av_y](double a, double b)-> double {return (a-av_x)*(b-av_y);});
    };

    auto product2=[av_x, av_y, n](std::vector<double> const& a, std::vector<double> const& b)->double
    {
        return std::inner_product(a.begin(), a.end(), b.begin(), 0.0)/n;
    };

    double szamlalo = product(x, y);
    double nevezo   = product(x, x);
    double p=product2(x,y)-av_y*av_x;

    double m=szamlalo/nevezo;
    double b=av_y-av_x*m;
    double sq_r=p*p / ((product2(x,x)-av_x*av_x)*(product2(y,y)-av_y*av_y));

    return {m, b, sq_r};          
}





int main() {
    std::cout.precision(16);

    std::vector<double> X = {3.0, 8.0,10.0, 17.0, 24.0, 27.0};
    std::vector<double> Y = {2.0, 8.0, 10.0, 13.0, 18.0, 20.0};
    std::array<double, 3> sol=illesztes(X,Y);

    std::array<double, 3> test={ 0.6933979858261841, 1.547929876911596, 0.9728504570950011};

    if(std:: abs(sol[0]-test[0])>1e-14 ||std:: abs(sol[1]-test[1])>1e-14 ||std:: abs(sol[2]-test[2])>1e-14 )
    {
        std::cout << "Rosszul számol a program :/ ";
    }
    else{
        std::cout << "m = " << sol[0] <<std::endl;
        std::cout << "b = " << sol[1] <<std::endl;   
        std::cout << "sq_r = " << sol[2]<<std::endl; 
    }              

    return 0;
}
