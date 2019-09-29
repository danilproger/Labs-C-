#include <iostream>
#include <vector>
#include <limits>
#include <bitset>
#include "tritset.h"
#include <algorithm>
int main() {
    tritset tritset(100);
    tritset[0] = True;
    tritset[1] = False;
    tritset[2] = tritset[1];
    tritset[16]= False;
    for (auto i : tritset.getVec()){
        std::cout<<std::bitset<32>(i)<<std::endl;
    }
}