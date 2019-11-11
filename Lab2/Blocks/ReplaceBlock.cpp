//
// Created by danil on 04.11.2019.
//

#include "ReplaceBlock.h"
#include "../Factory/BlockMaker.h"
#include "../Exceptions/WorkFlowException.h"

REGISTER_SHAPE(ReplaceBlock);

std::vector<std::string> ReplaceBlock::execute(std::vector<std::string> &text, std::vector<std::string> &args) const {
    bool flag = true;
    std::string word = args[0];
    std::string newWord = args[1];

    for (size_t i = 0; i < text.size(); i++) {
        if (text[i].find(word) == -1) continue;
        else {
            flag = false;
            std::string newLine = text[i].substr(0, text[i].find(word)) + newWord +
                                  text[i].substr(text[i].find(word) + word.length(), text[i].length() - 1);\
            text[i] = newLine;
        }
    }

    if (flag) throw WorkFlowException("Exception, cannot find word: " + word);

    return text;
}
