#include <iostream>
#include <complex>
#include "CSVParser/CSVParser.h"

int main() {
    std::ifstream f("in.csv", std::ios::binary);

    CSVParser<int, std::complex<float>, std::string> a(f);

    auto it1 = a.begin();
    auto it2 = a.begin();

    std::cout << (it1 == it2)<<std::endl;
    ++it1;
    std::cout << (it1 == it2)<<std::endl;
    ++it2;
    std::cout << (it1 == it2)<<std::endl;


    return 0;
}
