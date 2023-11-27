#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "base.h"

class Administration : public Base {
private:
    std::string fullName;
    std::string position;
    std::string responsibility;

public:
    Administration();  // Конструктор по умолчанию
    Administration(const std::string& fullName, const std::string& position, const std::string& responsibility);
    Administration(const Administration& other);  // Конструктор копирования
    ~Administration() override;  // Деструктор

    // Геттеры и сеттеры для данных

    void saveToFile(const std::string& filename) const override;
    void loadFromFile(const std::string& filename) override;
};

#endif // ADMINISTRATION_H

