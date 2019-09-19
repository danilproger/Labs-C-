#include <iostream>
//#include "TritSet.h"
#include <bitset>
#include <vector>

int &f(int &a){
    return a;
}
int main() {
	int b[] = {1};
    std::cout<<&f(b[0]);
	return 0;
}