//
// Created by danil on 30.09.2019.
//

#include "trit.h"

trit operator&(trit left, trit right) {
    if (left == trit::True && right == trit::True) return trit::True;
    if (right == trit::False || left == trit::False) return trit::False;
    return trit::Unknown;
}

trit operator|(trit left, trit right) {
    if (left == trit::True || right == trit::True) return trit::True;
    if (left == trit::False && right == trit::False) return trit::False;
    return trit::Unknown;
}

trit operator~(trit trit) {
    if (trit == trit::False) return trit::True;
    if (trit == trit::True) return trit::False;
    return trit::Unknown;
}
