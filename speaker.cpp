#include "speaker.h"

Speaker::Speaker() {
    // ����������� �� ���������
}

Speaker::Speaker(const std::string& fullName, const std::string& organization,
    const std::string& presentationTitle, const std::string& presentationAbstract)
    : fullName(fullName), organization(organization), presentationTitle(presentationTitle), presentationAbstract(presentationAbstract) {
    // ����������� � �����������
}

Speaker::Speaker(const Speaker& other)
    : fullName(other.fullName), organization(other.organization),
    presentationTitle(other.presentationTitle), presentationAbstract(other.presentationAbstract) {
    // ����������� �����������
}

Speaker::~Speaker() {
    // ����������
    std::cout << "Speaker destructor called.\n";
}

const std::string& Speaker::getFullName() const {
    return fullName;
}

const std::string& Speaker::getOrganization() const {
    return organization;
}

const std::string& Speaker::getPresentationTitle() const {
    return presentationTitle;
}

const std::string& Speaker::getPresentationAbstract() const {
    return presentationAbstract;
}

void Speaker::setFullName(const std::string& name) {
    fullName = name;
}

void Speaker::setOrganization(const std::string& org) {
    organization = org;
}

void Speaker::setPresentationTitle(const std::string& title) {
    presentationTitle = title;
}

void Speaker::setPresentationAbstract(const std::string& abstract) {
    presentationAbstract = abstract;
}

// ...

void Speaker::saveToFile(std::ofstream& file) const {
    // ���������� ���������� � ���� ��� ������ Speaker
    if (file.is_open()) {
        file << fullName << "\n";
        file << organization << "\n";
        file << presentationTitle << "\n";
        file << presentationAbstract << "\n";
    }
    else {
        std::cerr << "Error: Unable to open file for writing in Speaker::saveToFile.\n";
    }
}

void Speaker::loadFromFile(std::ifstream& file) {
    // ���������� �������� �� ����� ��� ������ Speaker
    if (file.is_open()) {
        std::getline(file, fullName);
        std::getline(file, organization);
        std::getline(file, presentationTitle);
        std::getline(file, presentationAbstract);
        // ����� ����� ����� �������� ��������� ������ ������ �� �����
    }
}



