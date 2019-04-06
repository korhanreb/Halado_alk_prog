#include "matrix.h"

int main()
 {
    	
    std::cout.precision(16);
    double tol = 1e-10;

    double a=4;
    matrix<double> A {2, {7.0, 5.0, 16.0, 8.0}};
    matrix<double> B {2, {5.0, 6.0, 7.0, 8.0}};

    matrix<double> C=A+B;

    
    

    std::cout << C (0,0) << std::endl;

    return 0;
}