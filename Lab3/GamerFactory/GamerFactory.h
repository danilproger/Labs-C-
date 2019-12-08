//
// Created by danil on 09.12.2019.
//

#ifndef LAB3_GAMERFACTORY_H
#define LAB3_GAMERFACTORY_H

#include "../Interfaces//IGamer.h"
#include "../Gamers/ConsoleGamer.h"
#include "../Gamers/RandomGamer.h"
#include "../Gamers/OptimalGamer.h"

class GamerFactory {
private:
    GamerFactory(){};

public:
    static GamerFactory &getInstance() {
        static GamerFactory factory;
        return factory;
    }

    IGamer *create(const GamerMode &mode){
        switch(mode){
            case CONSOLE:
                return new ConsoleGamer;
            case RANDOM:
                return new RandomGamer;
            case OPTIMAL:
                return new OptimalGamer;
            default: return nullptr;
        }
    }
};

#endif //LAB3_GAMERFACTORY_H
