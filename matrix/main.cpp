#include "matrix.h"
#include <string>

template<typename T>
void test(matrix<T> const& result, matrix<T> const& ref, std:: string text, double tol)
{
    if(result.Dim() != ref.Dim())
    {
        std::cout << "Nem egyeznek a dimenziók: "<< text << std::endl ;
    
    }
    if(result.size() != ref.size())
    {
        std::cout << "Nem egyeznek meg az elemszámok: "<< text << std::endl ;
    
    }
    for(int i=0; i < result.size() ; i++)
    {
        if(std:: abs(result[i]-ref[i])>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text << i << ". elemek, az eltérés: "<<result[i]-ref[i] << std::endl;            
        }
    }
}


int main(int,char**)
 {
    	
    std::cout.precision(16);
    double tol = 1e-10;

    double a=4.4;
    matrix<double> A {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A1 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A2 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A3 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A4 {2, {7.1, 5.5, 16.0, 8.2}};
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
    test(A1+=B,  ref, "A beépített összeadásnál összeadásnál a(z) ", tol); 
    }


    //teszt: kivonás
    
    {
    matrix<double> ref {2, {-0.6, -0.7, 0.2, -0.2}};
    test(C-D,  ref, "const&-const&: kivonásnál a(z) ", tol);      
    }
    {
    matrix<double> ref {2, {-2.7, 0.5, -8.8, -0.2}};
    test(C-A,  ref, "const&-&&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {0, -0.4, 0, 0.3}};
    test(B-D,  ref, "&&-const&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {2.1, -0.8, 9, -0.3}};
    test(A-B,  ref, "&&-&&: kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {2.1, -0.8, 9, -0.3}};
    test(A2-=B,  ref, "A beépített kivonásnáló a(z) ", tol);  
    }

    

    //teszt: skalárral szorzás
    
    {
    matrix<double> ref {2, {19.36, 26.4, 31.68, 35.2}};
    test(C*a,  ref, "const&: skalárral szorzásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {31.24, 24.2, 70.4, 36.08}};
    test(A*a,  ref, "&&: skalárral szorzásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {31.24, 24.2, 70.4, 36.08}};
    test(A3*=a,  ref, "A beépített skalárral szorzásnál a(z) ", tol); 
    }

    

    //teszt: skalárral osztás
    
    {
    matrix<double> ref {2, {1, 1.3636363636, 1.63636363636363, 1.818181818181}};
    test(C/a,  ref, "const&: skalárral osztásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {1.61363636363636, 1.25, 3.6363636363636363, 1.8636363636363}};
    test(A/a,  ref, "&&: skalárral osztásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {1.61363636363636, 1.25, 3.6363636363636363, 1.8636363636363}};
    test(A4/=a,  ref, "A beépített skalárral osztásnál a(z) ", tol);  
    }


    //teszt: vektorral szorzás
    
    {
    matrix<double> ref {2, {70.84, 86.6, 129.44, 161.6}};
    test(A*C,  ref, "A &&-const&: vektorral szorzásnál a(z) ", tol);  
    }

    {
     matrix<double> ref {2, {64, 78.68, 92, 113.84}};
    test(C*D,  ref, "A const&-const&: vektorral szorzásnál a(z) ", tol);  
    }

    {
    matrix<double> ref {2, {74, 91.48, 137.4, 170.5}};
    test(A*B,  ref, "A &&-&&: vektorral szorzásnál a(z) ", tol);  
    }
    

    //"move-oló" tesztek

    matrix<double> A5 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A6 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A7 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A8 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A9 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A10 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A11 {2, {7.1, 5.5, 16.0, 8.2}};
    matrix<double> A12 {2, {7.1, 5.5, 16.0, 8.2}};

    matrix<double> B2 {2, {5.0, 6.3, 7.0, 8.5}};
    matrix<double> B3 {2, {5.0, 6.3, 7.0, 8.5}}; 
    matrix<double> B4 {2, {5.0, 6.3, 7.0, 8.5}};

    //összeadás
    {
    matrix<double> ref {2, {11.5, 11.5, 23.2, 16.2}};
    test(C+std::move(A5),  ref, "const&-&&: MOVE összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {10.0, 13.0, 14.0, 16.7}};
    test(std::move(B2)+D,  ref, "&&-const&: MOVE összeadásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {12.1, 11.8, 23.0, 16.7}};
    test(std::move(A6)+B,  ref, "&&-&&: MOVE összeadásnál a(z) ", tol);
    }
    //kivonás
    {
    matrix<double> ref {2, {-2.7, 0.5, -8.8, -0.2}};
    test(C-std::move(A7),  ref, "const&-&&: MOVE kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {0, -0.4, 0, 0.3}};
    test(std::move(B3)-D,  ref, "&&-const&: MOVE kivonásnál a(z) ", tol);
    }
    {
    matrix<double> ref {2, {2.1, -0.8, 9, -0.3}};
    test(std::move(A8)-B,  ref, "&&-&&: MOVE kivonásnál a(z) ", tol);
    }
    //skalárral szorzás
    {
    matrix<double> ref {2, {31.24, 24.2, 70.4, 36.08}};
    test(std::move(A9)*a,  ref, "&&: MOVE skalárral szorzásnál a(z) ", tol);
    }
    //skalárral osztás
    {
    matrix<double> ref {2, {1.61363636363636, 1.25, 3.6363636363636363, 1.8636363636363}};
    test(std::move(A10)/a,  ref, "&&: MOVE skalárral osztásnál a(z) ", tol);
    }
    //teszt: vektorral szorzás  
    {
    matrix<double> ref {2, {70.84, 86.6, 129.44, 161.6}};
    test(std::move(A11)*C,  ref, "A &&-const&: MOVE vektorral szorzásnál a(z) ", tol);  
    }
    {
    matrix<double> ref {2, {64, 78.72, 92, 113.36}};
    test(C*std::move(B4),  ref, "A const&-&&: MOVE vektorral szorzásnál a(z) ", tol);  
    }
    {
    matrix<double> ref {2, {74, 91.48, 137.4, 170.5}};
    test(std::move(A12)*B,  ref, "A &&-&&: MOVE vektorral szorzásnál a(z) ", tol);  
    }  
   
    return 0;
}