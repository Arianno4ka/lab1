#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "base.h"
#include <fstream>
#include <string>


class Administration : public Base {
private:
    std::string fullName;
    std::string position;
    std::string responsibility;

public:
    Administration();
    Administration(const std::string& fullName, const std::string& position, const std::string& responsibility);
    Administration(const Administration& other);
    ~Administration() override;

    const std::string& getFullName() const;
    const std::string& getPosition() const;
    const std::string& getResponsibility() const;

    void setFullName(const std::string& name);
    void setPosition(const std::string& pos);
    void setResponsibility(const std::string& resp);
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // ADMINISTRATION_H
