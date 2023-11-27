#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <vector>

class Base {
public:
    virtual ~Base() = default;

    virtual void saveToFile(const std::string& filename) const = 0;
    virtual void loadFromFile(const std::string& filename) = 0;
};

#endif // BASE_H
