//
// Created by danil on 30.09.2019.
//

#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

enum trit {
    Unknown, False, True
};


trit operator&(trit left, trit right);

trit operator|(trit left, trit right);

trit operator~(trit trit);

#endif //LAB1_TRIT_H
