cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp Interfaces/IGamer.h Interfaces/IGameView.h ConsoleView/ConsoleView.cpp ConsoleView/ConsoleView.h Gamers/ConsoleGamer.cpp Gamers/ConsoleGamer.h Gamers/RandomGamer.cpp Gamers/RandomGamer.h Gamers/OptimalGamer.cpp Gamers/OptimalGamer.h GamePreferences.h Map/Map.cpp Map/Map.h GameController/GameController.cpp GameController/GameController.h Interfaces/IGameController.h)