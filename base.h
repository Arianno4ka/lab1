#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <vector>

class Base {
public:
    virtual ~Base() = default;

    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;
};

#endif // BASE_H
