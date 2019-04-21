#include <iostream>
#include "matrix.h"
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>

double f()
    { 
        std::random_device rd{};
        std::mt19937 gen(rd());
        std::normal_distribution<double> distr(100, 20);  //átlag, szórás
        return distr(gen);
    }


int main(int, char**) {


std::ofstream myfile("data.txt");


for (int j=0; j<100; ++j)  //dim megadása
{
    matrix<double> A(j);
    matrix<double> B(j);   

    
    std::generate(A.begin(), A.end(), f);
    std::generate(B.begin(), B.end(), f);


    //std:: cout << A[0] << std:: endl;
    //std:: cout << B(0,0) << std:: endl;

    int N{5};  //hányszor végezzük el az időmérést
    std::vector<long long> T1(N);
    std::vector<long long> T2(N);

    for (int i=0; i<N; ++i)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        A*B;
        auto t2 = std::chrono::high_resolution_clock::now();
    
        auto t3 = std::chrono::high_resolution_clock::now();
        std::move(A)*B;
        auto t4 = std::chrono::high_resolution_clock::now();
   
    
        T1[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
        T2[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count();
    }
    

    auto min_value1 = *std::min_element(T1.begin(),T1.end());
    auto min_value2 = *std::min_element(T2.begin(),T2.end());
    myfile << j << ", " << min_value1 << ", " << min_value2  << ", \n";
    

}


return 0;
}
