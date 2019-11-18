cmake_minimum_required(VERSION 3.15)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Lab2 main.cpp Interfaces/IBlock.h Factory/BlockFactory.cpp Factory/BlockFactory.h Interfaces/IBlockMaker.h Factory/BlockMaker.h Blocks/SortBlock.cpp Blocks/SortBlock.h Blocks/ReadBlock.cpp Blocks/ReadBlock.h Blocks/WriteBlock.cpp Blocks/WriteBlock.h Blocks/GrepBlock.cpp Blocks/GrepBlock.h Blocks/ReplaceBlock.cpp Blocks/ReplaceBlock.h Blocks/DumpBlock.cpp Blocks/DumpBlock.h Interfaces/IWorkFlow.h WorkFlow/WorkFlow.cpp WorkFlow/WorkFlow.h Interfaces/IParser.h Parser/Parser.cpp Parser/Parser.h Exceptions/ParserException.cpp Exceptions/ParserException.h Exceptions/WorkFlowException.cpp Exceptions/WorkFlowException.h Exceptions/FactoryException.cpp Exceptions/FactoryException.h)