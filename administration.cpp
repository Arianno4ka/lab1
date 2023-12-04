#include "administration.h"

Administration::Administration() {
    // ����������� �� ���������
}

Administration::Administration(const std::string& fullName, const std::string& position, const std::string& responsibility)
    : fullName(fullName), position(position), responsibility(responsibility) {
    // ����������� � �����������
}

Administration::Administration(const Administration& other)
    : fullName(other.fullName), position(other.position), responsibility(other.responsibility) {
    // ����������� �����������
}

Administration::~Administration() {
    // ����������
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
    // ���������� ���������� � ���� ��� ������ Administration
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
    // ���������� �������� �� ����� ��� ������ Administration
    if (file.is_open()) {
        std::getline(file, fullName);
        std::getline(file, position);
        std::getline(file, responsibility);
        // ����� ����� ����� �������� ��������� ������ ������ �� �����
    }
    else {
        std::cerr << "Error: Unable to open file for reading in Administration::loadToFile.\n";
    }
}