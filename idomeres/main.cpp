#include <iostream>
#include "matrix.h"
#include <vector>
#include <random>
#include <chrono>
#include <fstream>


int main(int, char**) {


std::ofstream myfile("data.txt", std::ios::out | std::ios::app);


for (int j=0; j<100; ++j)  //dim megadása
{
    matrix<double> A(j);
    matrix<double> B(j);
    for(int i=0; i<j*j; ++i) //A feltöltése
    {
        std::random_device rd{};
        std::mt19937 gen(rd());
        std::normal_distribution<double> distr(100, 20);  //átlag, szórás
        A[i]=distr(gen);
    }
    for(int i=0; i<j*j; ++i) //B feltöltése
    {
        std::random_device rd{};
        std::mt19937 gen(rd());
        std::normal_distribution<double> distr(100, 20);  //átlag, szórás
        B[i]=distr(gen);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    A*B;
    auto t2 = std::chrono::high_resolution_clock::now();
    
    auto t3 = std::chrono::high_resolution_clock::now();
    std::move(A)*B;
    auto t4 = std::chrono::high_resolution_clock::now();
   
    
    long long n1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
    long long n2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count();
    ;

    
    myfile << j << ", " << n1 << ", " << n2  << ", \n";
    

}


return 0;
}
