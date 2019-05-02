#include "matrix2.h"
#include <string>
#include <sstream>

template<typename T>
void test1(Matrix2<T> const& result, Matrix2<T> const& ref, std:: string text, double tol)
{
    if(std:: abs(result.x1-ref.x1)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 1. elemek, az eltérés: "<< result.x1-ref.x1 << std::endl;            
        }
    if(std:: abs(result.x2-ref.x2)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 2. elemek, az eltérés: "<< result.x2-ref.x2 << std::endl;            
        }
    if(std:: abs(result.x3-ref.x3)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 3. elemek, az eltérés: "<<result.x3-ref.x3 << std::endl;            
        }
    if(std:: abs(result.x4-ref.x4)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 4. elemek, az eltérés: "<<result.x4-ref.x4 << std::endl;            
        }
}

template<typename T>
void test2(Vector2d<T> const& result, Vector2d<T> const& ref, std:: string text, double tol)
{
    if(std:: abs(result.x-ref.x)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 1. elemek, az eltérés: "<< result.x-ref.x << std::endl;            
        }
    if(std:: abs(result.y-ref.y)>tol)
        {
           std::cout << "Nem egyeznek a(z): "<< text <<  "az 2. elemek, az eltérés: "<< result.y-ref.y << std::endl;            
        }
}

int main(int, char**) {
    	
    std::cout.precision(16);
    double tol = 1e-6;

    double a=4.4;
    Matrix2<double> A {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> B {5.0, 6.3, 7.0, 8.5};
    Matrix2<double> const C {4.4, 6.0, 7.2, 8.0};
    Matrix2<double> const D {5.0, 6.7, 7.0, 8.2};
    Vector2d<double> b = {-25.5, 10.2};
    Vector2d<double> const c = { 11.5, -55.6};
    Vector2d<int> const e = { 2, -3};

    //nem beépített tesztek
    //összeadás
    {
    Matrix2<double> ref {9.4, 12.7, 14.2, 16.2};
    test1(C+D,  ref, "const&-const&: összeadásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {11.5, 11.5, 23.2, 16.2};
    test1(C+A,  ref, "const&-&&: összeadásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {10.0, 13.0, 14.0, 16.7};
    test1(B+D,  ref, "&&-const&: összeadásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {12.1, 11.8, 23.0, 16.7};
    test1(A+B,  ref, "&&-&&: összeadásnál a(z) ", tol);
    }
    //kivonás
    {
    Matrix2<double> ref {-0.6, -0.7, 0.2, -0.2};
    test1(C-D,  ref, "const&-const&: kivonásnál a(z) ", tol);      
    }
    {
    Matrix2<double> ref {-2.7, 0.5, -8.8, -0.2};
    test1(C-A,  ref, "const&-&&: kivonásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {0, -0.4, 0, 0.3};
    test1(B-D,  ref, "&&-const&: kivonásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {2.1, -0.8, 9, -0.3};
    test1(A-B,  ref, "&&-&&: kivonásnál a(z) ", tol);
    }
    
    // skalárral szorzás    
    {
    Matrix2<double> ref {19.36, 26.4, 31.68, 35.2};
    test1(C*a,  ref, "const&: (balról) skalárral szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {31.24, 24.2, 70.4, 36.08};
    test1(A*a,  ref, "&&: (balról)  skalárral szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {19.36, 26.4, 31.68, 35.2};
    test1(a*C,  ref, "const&: (jobbról) skalárral szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {31.24, 24.2, 70.4, 36.08};
    test1(a*A,  ref, "&&: (jobbról) skalárral szorzásnál a(z) ", tol);
    }

    //saklárral osztás

    {
    Matrix2<double> ref {1, 1.3636363636, 1.63636363636363, 1.818181818181};
    test1(C/a,  ref, "const&: skalárral osztásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {1.61363636363636, 1.25, 3.6363636363636363, 1.8636363636363};
    test1(A/a,  ref, "&&: skalárral osztásnál a(z) ", tol);
    }

    //mátrixszal szorzás
    {
    Matrix2<double> ref {74, 91.48, 137.4, 170.5};
    test1(A*B,  ref, "&&-&&: mátrixszal szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {70.84, 86.6, 129.44, 161.6};
    test1(A*C,  ref, "&&-const&: mátrixszal szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {127.24, 73.4, 179.12, 105.2};
    test1(C*A,  ref, "const&-&&: mátrixszal szorzásnál a(z) ", tol);
    }
    {
    Matrix2<double> ref {64, 78.68, 92, 113.84};
    test1(C*D,  ref, "const&-&&: mátrixszal szorzásnál a(z) ", tol);
    }

    // mátrix / mátrix osztás
    {
    Matrix2<double> ref {-13.65625, 10.76875, -49.125, 37.375};
    test1(A/B,  ref, "&&-&&: mátrix / mátrix osztásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {-2.15, 2.3, -8.62, 7.49};
    test1(A/C,  ref, "&&-const&: mátrix / mátrix osztásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {2.012088, -0.617864, 2.3156481, -0.577569};
    test1(C/A,  ref, "const&-&&: mátrix / mátrix osztásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {1.00339, -0.0881356, -0.515254, 1.39661};
    test1(C/D,  ref, "const&-const&: mátrix / mátrix osztásnál a(z) ", tol);  
    }

    // skalár / mátrix osztás
    {
    Matrix2<double> ref {-1.211551, 0.812626, 2.364003, -1.049026};
    test1(a/A,  ref, "&&: konstans / mátrix osztásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {-6.115254, 4.996610, 5.220339, -3.728814};
    test1(a/D,  ref, "const&: konstans / mátrix osztásnál a(z) ", tol);  
    }

    // mátrix- vektor szorzás
    {
    Vector2d<double> ref {-124.95, -324.36};
    test2(A*b,  ref, "&&-&&: mátrix- vektor szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-224.15, -271.92};
    test2(A*c,  ref, "&&-const&: mátrix- vektor szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-17.85, -56.61};
    test2(b*A,  ref, "&&-&&: vektor- mátrix szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-807.95, -392.67};
    test2(c*A,  ref, "const&-&&: vektor- mátrix szorzásnál a(z) ", tol);  
    }

    {
    Vector2d<double> ref {-9.2, -9.6};
    test2(C*e,  ref, "const&-const&: mátrix- vektor szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-283, -362};
    test2(C*c,  ref, "const&-&&: mátrix- vektor szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-12.8, -12};
    test2(e*C,  ref, "const&-const&: vektor- mátrix szorzásnál a(z) ", tol);  
    }
    {
    Vector2d<double> ref {-349.72, -375.8};
    test2(c*C,  ref, "&&-const&: vektor- mátrix szorzásnál a(z) ", tol);  
    }




    // beépített függvények tesztelése
    Matrix2<double> A1 {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> A2 {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> A3 {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> A4 {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> A5 {7.1, 5.5, 16.0, 8.2};
    Matrix2<double> A6 {7.1, 5.5, 16.0, 8.2};
    
    {
    Matrix2<double> ref {12.1, 11.8, 23.0, 16.7};
    test1(A1+=B,  ref, "A beépített összeadásnál összeadásnál a(z) ", tol); 
    }
    {
    Matrix2<double> ref {2.1, -0.8, 9, -0.3};
    test1(A2-=B,  ref, "A beépített kivonásnáló a(z) ", tol);  
    }
    {
    Matrix2<double> ref {31.24, 24.2, 70.4, 36.08};
    test1(A3*=a,  ref, "A beépített skalárral szorzásnál a(z) ", tol); 
    }
    {
    Matrix2<double> ref {1.61363636363636, 1.25, 3.6363636363636363, 1.8636363636363};
    test1(A4/=a,  ref, "A beépített skalárral osztásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {74, 91.48, 137.4, 170.5};
    test1(A5*=B,  ref, "A beépített mátrixxal szorzásnál a(z) ", tol);  
    }
    {
    Matrix2<double> ref {-13.65625, 10.76875, -49.125, 37.375};
    test1(A6/=B,  ref, "A beépített mátrixxal osztásnál a(z) ", tol);  
    }

    Matrix2<double> M {5, -3, 6, -3};

    std::cout << determinant(M) << inv(M)  << std:: endl;


    


    

	return 0;
}
