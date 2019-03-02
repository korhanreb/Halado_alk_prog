#include <iostream>
#include <math.h>

double sq(double x)
{
    return x*x;
}

//solve a*x*x+b*x+c = 0
void solve2(double a, double b, double c)
{
  double D=sq(b)-4*a*c;
  if(D <0.0 )
  {
    std::cout << "No solution\n";
  }
  else if(D==0.0)
  {
    std::cout << "The solution is: " << -b/(2*a) << "\n";
  }
  else
  {
    std::cout << "The solutions are: " << (-b+sqrt(D))/(2*a) << " and " << (-b-sqrt(D))/(2*a) <<"\n";
  }
  
}

 
int main()
{
    solve2(1, 1, 1);
    return 0;
}
