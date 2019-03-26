#include "vector2.h"

int main(int, char**) {
    	
    std::cout.precision(16);
    double tol = 1e-6;

	Vector2d<double> a = {99.7, 11.2};
    Vector2d<int> b = { 11, -96};

    double ref_1 = 21.5;
    double test_1 = dot(a, b);
    if (std::abs(test_1 - ref_1) > tol)
    {
		std::cout << "Skalár szorzat fügvényével valami baj van. " << std::endl;
        exit(-1);
    }
    

	double ref_2 = 10065.53;
    double test_2 = sqlength(a);
    if (std::abs(test_2 - ref_2) > tol)
    {
		std::cout << "A hossznégyzet kiszámításánál valami baj van. " << std::endl;
        exit(-1);
    }


    double ref_3 = 100.327114979;
    double test_3 = length(a);
    if (std::abs(test_3 - ref_3) > tol)
    {
		std::cout << "A hossz kiszámításánál valami baj van. " << std::endl;
        exit(-1);
    }
    
    Vector2d<double> ref_4 = {0.99374929719516738063382, 0.1116348257631481912046};
    Vector2d<double> test_4 = normalize(a);
    if (abs(test_4.x - ref_4.x) > tol || abs(test_4.y - ref_4.y) > tol )
    {
		std::cout << "A normálásnál valami baj van. " << std::endl;
        exit(-1);
    }
    
	double c = 7.6;

    Vector2d<double> ref_5 = {757.72, 85.12};
    Vector2d<double> test_5 = a * c;
    Vector2d<double> test_5_2 = c * a;

    if (abs(test_5.x-ref_5.x) > tol || abs(test_5.y-ref_5.y) > tol  || abs(test_5_2.x - ref_5.x) > tol || abs(test_5_2.y - ref_5.y) > tol)
    {
		std::cout << "Skalárral való szorzással valami baj van"  << std::endl;
        exit(-1);
    }
    
    
    Vector2d<double> ref_7 = { 13.11842105263, 1.4736842105263};
    Vector2d<double> test_7= a / c;

    if (abs(test_7.x - ref_7.x) > tol || abs(test_7.y - ref_7.y) > tol )
    {
		std::cout << "Skalárral való osztással valami baj van"<<  std::endl;
        exit(-1);
    }

	Vector2d<double> ref_8 = { 110.7, -84.8};
    Vector2d<double> test_8= a + b ;

    if (abs(test_8.x- ref_8.x) > tol || abs(test_8.y- ref_8.y) > tol )
    {
		std::cout << "Az összeadás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }

	Vector2d<double> ref_9 = { 88.7, 107.2};
    Vector2d<double> test_9= a - b ;

    if (abs(test_9.x- ref_9.x) > tol || abs(test_9.y- ref_9.y) > tol )
    {
		std::cout << "Az kivonás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    
	///// beépítettek tesztelése
    

    Vector2d<double> ref_10 = { 110.7, -84.8};
    a += b; 
    if (abs(a.x-ref_10.x) > tol || abs(a.y-ref_10.y)> tol )
    {
		std::cout << "Az beépített összeadás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
	

	a = {99.7, 11.2};
	Vector2d<double> ref_11 = { 88.7, 107.2};
    a -= b; 
    if (abs(a.x-ref_11.x) > tol || abs(a.y-ref_11.y) > tol )
    {
		std::cout << "Az beépített kivonás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
	a = {99.7, 11.2};
	Vector2d<double> ref_12 = { 757.72, 85.12};
    a *= c; 
    if (abs(a.x-ref_12.x) > tol || abs(a.y-ref_12.y) > tol )
    {
		std::cout << "Az beépített szorzás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
	a = {99.7, 11.2};
	Vector2d<double> ref_13 = { 13.11842105263, 1.4736842105263};
    a /= c; 
    if (abs(a.x-ref_13.x) > tol || abs(a.y-ref_13.y) > tol )
    {
		std::cout << "Az beépített osztás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    
	return 0;
}
