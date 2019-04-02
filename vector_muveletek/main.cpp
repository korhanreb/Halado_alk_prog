#include "vector2.h"

int main(int, char**) {
    	
    std::cout.precision(16);
    double tol = 1e-10;

	Vector2d<double> a = {99.7, 11.2};
    const Vector2d<int> b = { 11, -96};
    {
    double ref = 21.5;
    double test = dot(a, b);
    if (std::abs(test - ref) > tol)
    {
		std::cout << "Skalár szorzat fügvényével valami baj van. " << std::endl;
        exit(-1);
    }
    }

    {
	double ref = 10065.53;
    double test = sqlength(a);
    if (std::abs(test - ref) > tol)
    {
		std::cout << "A hossznégyzet kiszámításánál valami baj van. " << std::endl;
        exit(-1);
    }
    }
    
    {
    double ref = 100.327114979;
    double test = length(a);
    if (std::abs(test - ref) > tol)
    {
		std::cout << "A hossz kiszámításánál valami baj van. " << std::endl;
        exit(-1);
    }
    }

    {
    Vector2d<double> ref = {0.99374929719516738063382, 0.1116348257631481912046};
    Vector2d<double> test = normalize(a);
    if (std::abs(test.x - ref.x) > tol || std::abs(test.y - ref.y) > tol )
    {
		std::cout << "A normálásnál valami baj van. " << std::endl;
        exit(-1);
    }
    }
	const double c = 7.6;

    {
    Vector2d<double> ref = {757.72, 85.12};
    Vector2d<double> test = a * c;
    Vector2d<double> test2 = c * a;
    if (std::abs(test.x-ref.x) > tol || std::abs(test.y-ref.y) > tol  || std::abs(test2.x - ref.x) > tol || std::abs(test2.y - ref.y) > tol)
    {
		std::cout << "Skalárral való szorzással valami baj van"  << std::endl;
        exit(-1);
    }
    }
    
    {
    Vector2d<double> ref = { 13.11842105263, 1.4736842105263};
    Vector2d<double> test= a / c;

    if (std::abs(test.x - ref.x) > tol || std::abs(test.y - ref.y) > tol )
    {
		std::cout << "Skalárral való osztással valami baj van"<<  std::endl;
        exit(-1);
    }
    }

    {
	Vector2d<double> ref = { 110.7, -84.8};
    Vector2d<double> test= a + b ;

    if (std::abs(test.x- ref.x) > tol || std::abs(test.y- ref.y) > tol )
    {
		std::cout << "Az összeadás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }

    {
	Vector2d<double> ref = { 88.7, 107.2};
    Vector2d<double> test= a - b ;

    if (std::abs(test.x- ref.x) > tol || std::abs(test.y- ref.y) > tol )
    {
		std::cout << "Az kivonás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }
	///// beépítettek tesztelése
    {
    a = {99.7, 11.2};
    Vector2d<double> ref = { 110.7, -84.8};
    a += b; 
    if (std::abs(a.x-ref.x) > tol || std::abs(a.y-ref.y)> tol )
    {
		std::cout << "Az beépített összeadás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }

	{
    a = {99.7, 11.2};
	Vector2d<double> ref = { 88.7, 107.2};
    a -= b; 
    if (std::abs(a.x-ref.x) > tol || std::abs(a.y-ref.y) > tol )
    {
		std::cout << "Az beépített kivonás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }

    {
	a = {99.7, 11.2};
	Vector2d<double> ref = { 757.72, 85.12};
    a *= c; 
    if (std::abs(a.x-ref.x) > tol || std::abs(a.y-ref.y) > tol )
    {
		std::cout << "Az beépített szorzás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }

    {
	a = {99.7, 11.2};
	Vector2d<double> ref = { 13.11842105263, 1.4736842105263};
    a /= c; 
    if (std::abs(a.x-ref.x) > tol || std::abs(a.y-ref.y) > tol )
    {
		std::cout << "Az beépített osztás operátorral valami baj van"<<  std::endl;
        exit(-1);
    }
    }
    
	return 0;
}
