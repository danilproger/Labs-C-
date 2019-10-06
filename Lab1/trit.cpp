//
// Created by danil on 30.09.2019.
//

#include "trit.h"

enum trit operator&(enum trit left, enum trit right) {
    if (left == True && right == True) return True;
    if (right == False || left == False) return False;
    return Unknown;
}

enum trit operator|(enum trit left, enum trit right) {
    if (left == True || right == True) return True;
    if (left == False && right == False) return False;
    return Unknown;
}

enum trit operator~(enum trit trit) {
    if (trit == False) return True;
    if (trit == True) return False;
    return Unknown;
}