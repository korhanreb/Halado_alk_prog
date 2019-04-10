#include "matrix.h"
#include <string>

template<typename T>
void test(matrix<T> const& result, matrix<T> const& ref, std:: string text, double tol)
{
    if(result.size() != ref.size())
    {
        std::cout << "Nem egyeznek a dimenziók: "<< text << std::endl ;
    
    }
    for(int i=0; i < result.size()*result.size() ; i++)
    {
        if(std:: abs(result[i]-ref[i])>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text << i << ". elemben";            
        }
    }
}


int main(int,char**)
 {
    	
    std::cout.precision(16);
    double tol = 1e-10;

    double a=4;
    matrix<double> A {2, {7.0, 5.0, 16.0, 8.0}};
    matrix<double> B {2, {5.0, 6.0, 7.0, 8.0}};

    matrix<double> C=A+B;
    matrix<double> ref {2, {12.0, 22.0, 23.0, 16.0}};
    test(C,  ref, "const&-const&:összeadás", tol);

    
    

    std::cout << C (0,0) << std::endl;

    return 0;
}