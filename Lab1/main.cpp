#include <iostream>
#include <vector>
#include <limits>
#include <bitset>
#include "tritset.h"
#include <algorithm>

int main() {
    tritset tritset(16);
    tritset[0] = False;
    std::cout<<std::bitset<32>(tritset.getAr()[0])<<std::endl;
    tritset[10000000] = True;
    std::cout<<std::bitset<32>(tritset.getAr()[0])<<std::endl;
    std::cout<<tritset.getSize()<<' '<<tritset.getCapacity()<<std::endl;
    tritset[10000000] = Unknown;
    tritset.shrink();
    std::cout<<tritset.getSize()<<' '<<tritset.getCapacity()<<std::endl<<tritset.cardinality(False)<<std::endl;
    std::cout<<std::bitset<32>(tritset.getAr()[0])<<std::endl;
}