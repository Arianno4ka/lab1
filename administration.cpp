#include "administration.h"

Administration::Administration() {
    // Конструктор по умолчанию
}

Administration::Administration(const std::string& fullName, const std::string& position, const std::string& responsibility)
    : fullName(fullName), position(position), responsibility(responsibility) {
    // Конструктор с параметрами
}

Administration::Administration(const Administration& other)
    : fullName(other.fullName), position(other.position), responsibility(other.responsibility) {
    // Конструктор копирования
}

Administration::~Administration() {
    // Деструктор
    std::cout << "Administration destructor called.\n";
}

const std::string& Administration::getFullName() const {
    return fullName;
}

const std::string& Administration::getPosition() const {
    return position;
}

const std::string& Administration::getResponsibility() const {
    return responsibility;
}

void Administration::setFullName(const std::string& name) {
    fullName = name;
}

void Administration::setPosition(const std::string& pos) {
    position = pos;
}

void Administration::setResponsibility(const std::string& resp) {
    responsibility = resp;
}
void Administration::saveToFile(std::ofstream& file) const {
    // Реализация сохранения в файл для класса Administration
    if (file.is_open()) {
        file << fullName << "\n";
        file << position << "\n";
        file << responsibility << "\n";
    }
    else {
        std::cerr << "Error: Unable to open file for writing in Administration::saveToFile.\n";
    }
}

void Administration::loadFromFile(std::ifstream& file) {
    // Реализация загрузки из файла для класса Administration
    if (file.is_open()) {
        std::getline(file, fullName);
        std::getline(file, position);
        std::getline(file, responsibility);
        // Здесь можно также добавить обработку ошибок чтения из файла
    }
    else {
        std::cerr << "Error: Unable to open file for reading in Administration::loadToFile.\n";
    }
}