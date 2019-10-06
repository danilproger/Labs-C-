//
// Created by danil on 30.09.2019.
//

#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

enum trit {
    Unknown, False, True
};

enum trit operator&(enum trit left, enum trit right);

enum trit operator|(enum trit left, enum trit right);

enum trit operator~(enum trit trit);

#endif //LAB1_TRIT_H
