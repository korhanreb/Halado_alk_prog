#include "matrix.h"
#include <string>

template<typename T>
void test(matrix<T> const& result, matrix<T> const& ref, std:: string text, double tol)
{
    if(result.size() != ref.size())
    {
        std::cout << "Nem egyeznek a dimenziók: "<< text << std::endl ;
    
    }
    for(int i=0; i < result.size() ; i++)
    {
        if(std:: abs(result[i]-ref[i])>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text << i << ". elemek" << std::endl;            
        }
    }
}


int main(int,char**)
 {
    	
    std::cout.precision(16);
    double tol = 1e-10;

    double a=4;
    matrix<double> A {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> B {2, {5.0, 6.3, 7.0, 8.5}};
    matrix<double> const C {2, {4.4, 6.0, 7.2, 8.0}};
    matrix<double> const D {2, {5.0, 6.7, 7.0, 8.2}};

    //teszt: összeadás
    {
    matrix<double> ref {2, {9.4, 12.7, 14.2, 16.2}};
    test(C+D,  ref, "const&-const&: összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {11.5, 11.5, 23.2, 16.2}};
    test(C+A,  ref, "const&-&&: összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {10.0, 13.0, 14.0, 16.7}};
    test(B+D,  ref, "&&-const&: összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {12.1, 11.8, 23.0, 16.7}};
    test(A+B,  ref, "&&-&&: összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {12.1, 11.8, 23.0, 16.7}};
    test(A+=B,  ref, "A beépített összeadásnál összeadásnál a(z) ", tol); //itt az A megváltozott
    }



    {
    matrix<double> ref {2, {0.6, -0.7, 0.2, 0.0}};
    test(C-D,  ref, "const&-const&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {11.5, 11.5, 23.2, 16.2}};
    test(C-A,  ref, "const&-&&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {10.0, 13.0, 14.0, 16.7}};
    test(B-D,  ref, "&&-const&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {12.1, 11.8, 23.0, 16.7}};
    test(A-B,  ref, "&&-&&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {12.1, 11.8, 23.0, 16.7}};
    test(A-=B,  ref, "A beépített kivonásnál összeadásnál a(z) ", tol);
    }

    return 0;
}