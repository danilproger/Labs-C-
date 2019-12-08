#include <getopt.h>
#include <cstring>
#include "GameController/GameController.h"
#include "ConsoleView/ConsoleView.h"

void readInput(GamerMode &gamer_1, GamerMode &gamer_2, int &count, char **argv, int argc){
    char *opts = strdup("hc:f:s:");
    const struct option long_options[] = {
            {"help", 0, nullptr, 'h'},
            {"second", 1, nullptr, 's'},
            {"first", 1, nullptr, 'f'},
            {"count", 1, nullptr, 'c'}
    };

    int opt;
    while((opt = getopt_long(argc, argv, opts, long_options, nullptr))!=-1){
        switch (opt){
            case 'h':
                break;
            case 'c':
                count = atoi(optarg);
                break;
            case 'f':
                if(std::string(optarg)=="console") gamer_1 = CONSOLE;
                if(std::string(optarg)=="optimal") gamer_1 = OPTIMAL;
                break;
            case 's':
                if(std::string(optarg)=="console") gamer_2 = CONSOLE;
                if(std::string(optarg)=="optimal") gamer_2 = OPTIMAL;
                break;
        }
    }

    delete opts;
}

int main(int argc, char **argv) {
    GameController gm;
    ConsoleView view;
    GamerMode gamer_1 = RANDOM;
    GamerMode gamer_2 = RANDOM;
    int countGames = 1;
    
    readInput(gamer_1, gamer_2, countGames, argv, argc);

    gm.run(gamer_1, gamer_2, countGames);
    return 0;
}