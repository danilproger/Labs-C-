//
// Created by danil on 04.11.2019.
//

#include "GrepBlock.h"
#include "../Factory/BlockMaker.h"
#include "../Exceptions/WorkFlowException.h"

REGISTER_BLOCK(GrepBlock, grep);

void GrepBlock::execute(std::vector<std::string> &text, const std::vector<std::string> &args) const {
    if(args.size()!=1) throw WorkFlowException("Args for grep != 1");
    bool flag = true;
    std::string word = args[0];

    for (size_t i = 0; i < text.size(); i++) {
        if (text[i].find(word) == -1) continue;
        else {
            flag = false;
            std::string newLine = text[i].substr(0, text[i].find(word)) +
                                  text[i].substr(text[i].find(word) + word.length(), text[i].length() - 1);
            text[i] = newLine;
        }
    }

    if(flag) throw WorkFlowException("Exception, cannot find word: " + word);
}

const blockType GrepBlock::getType() const {
    return OTHER;
}
