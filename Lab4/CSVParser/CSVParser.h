//
// Created by danil on 15.12.2019.
//

#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

//out tuple
template<size_t i, typename... Args>
typename std::enable_if<(i >= sizeof...(Args))>::type
printTuple(std::ostream &, const std::tuple<Args...> &) { return; }

template<size_t i, typename... Args>
typename std::enable_if<(i < sizeof...(Args))>::type
printTuple(std::ostream &os, const std::tuple<Args...> &tup) {
    if (i != 0)
        os << ", ";
    os << std::get<i>(tup);
    printTuple<i + 1>(os, tup);
}

template<typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &tup) {
    printTuple<0>(os, tup);
    return os << std::endl;
}

//convert tuple to types
template<typename T>
T convert(const std::string &cell) {
    T t;
    std::stringstream ss(cell);
    ss >> t;
    return T(t);
}

template<>
std::string convert(const std::string &cell) {
    return cell;
}

//parse csv row
std::vector<std::string> parseLine(const std::string &line, char delimiter) {
    std::vector<std::string> parsedLine;
    for (size_t i = 0; i < line.size(); ++i) {
        std::string cell;

        while (i < line.size() && line[i] != delimiter) {
            cell += line[i];
            i++;
        }

        if (!cell.empty()) {
            parsedLine.push_back(cell);
        }
    }
    return parsedLine;
}

//creating tuple
template<size_t i, typename... Args>
typename std::enable_if<(i >= sizeof...(Args))>::type
makeTuple(const std::vector<std::string> &cells, std::tuple<Args...> &tup) {
    return;
}

template<size_t n, typename... Args>
typename std::enable_if<(n < sizeof...(Args))>::type
makeTuple(const std::vector<std::string> &cells, std::tuple<Args...> &tup) {
    std::get<n>(tup) = convert<typename std::tuple_element<n, std::tuple<Args...>>::type>(cells[n]);
    makeTuple<n + 1>(cells, tup);
}


template<typename ... Args>
class CSVParser {
private:
    char _delimiter;
    std::ifstream &_stream;

public:
    class Iterator;

    explicit CSVParser(std::ifstream &stream, size_t skipLines = 0) : _stream(stream) {
        std::string line;
        _delimiter = ';';
        for (size_t i = 0; i < skipLines; ++i) {
            std::getline(_stream, line);
        }
    }

    void setDelimiter(char delimiter) { _delimiter = delimiter; }

    Iterator begin() const {
        return Iterator(_stream);
    }

    Iterator end() const {
        return Iterator();
    }

    class Iterator {
    private:
        char _delimiter;
        size_t _position;
        std::ifstream *_stream;
        std::tuple<Args...> _row;

        void readNextRow(std::ifstream &stream, char delimiter) {
            std::string line;
            stream.seekg(_position);
            std::getline(stream, line);
            _position = stream.tellg();

            if (stream.eof() || line.empty())
                return;
            makeTuple<0>(parseLine(line, delimiter), _row);
        }

    public:
        Iterator(std::ifstream &stream, char delimiter = ';') : _stream(&stream), _delimiter(delimiter) {
            _position = 0;
            readNextRow((*_stream), _delimiter);
        }

        Iterator() : _stream(nullptr) {}

        std::tuple<Args...> const &operator*() const { return _row; }

        Iterator &operator++() {
            readNextRow((*_stream), _delimiter);
            if(_stream->eof()) _stream = nullptr;
            return *this;
        }

        bool operator==(Iterator &it) {
            return ((_position==it._position) || ((this->_stream == nullptr) && (it._stream == nullptr)));
        }

        bool operator!=(Iterator &it) { return !((*this) == it); }
    };
};

#endif //LAB4_CSVPARSER_H