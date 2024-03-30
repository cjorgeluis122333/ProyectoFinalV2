//
// Created by Jorge Luis on 3/29/2024.
//

#ifndef PROYECTOFINALV2_MAININSERTEXEPTION_H
#define PROYECTOFINALV2_MAININSERTEXEPTION_H


#include <stdexcept>

class MainInsertExeption : public std::runtime_error {
public:
    explicit MainInsertExeption(const std::string& message) : std::runtime_error(message) {}
};


#endif //PROYECTOFINALV2_MAININSERTEXEPTION_H
