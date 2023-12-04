// В классе Conference.cpp

#include "conference.h"
#include <iostream>
#include <fstream>

Conference::Conference() {
}

Conference::~Conference() {
    // Освобождаем память, выделенную для каждого элемента
    for (auto speaker : speakers) {
        delete speaker;
    }

    for (auto admin : administration) {
        delete admin;
    }

    for (auto event : events) {
        delete event;
    }
    std::cout << "Conference destructor called.\n";
}

void Conference::addSpeaker(const Speaker& speaker) {
    // Выделяем память для нового элемента и добавляем его в вектор
    speakers.push_back(new Speaker(speaker));
}

void Conference::addAdministration(const Administration& admin) {
    administration.push_back(new Administration(admin));
}

void Conference::addEvent(const Event& event) {
    events.push_back(new Event(event));
}

void Conference::removeSpeaker(const std::string& name) {
    // Ищем спикера по имени и удаляем его, освобождая память
    auto it = std::find_if(speakers.begin(), speakers.end(),
        [name](const Speaker* speaker) { return speaker->getFullName() == name; });

    if (it != speakers.end()) {
        delete* it;
        speakers.erase(it);
    }
}

void Conference::removeAdministration(const std::string& name) {
    auto it = std::find_if(administration.begin(), administration.end(),
        [name](const Administration* admin) { return admin->getFullName() == name; });

    if (it != administration.end()) {
        delete* it;
        administration.erase(it);
    }
}

void Conference::removeEvent(const std::string& title) {
    auto it = std::find_if(events.begin(), events.end(),
        [title](const Event* event) { return event->getTitle() == title; });

    if (it != events.end()) {
        delete* it;
        events.erase(it);
    }
}

void Conference::printEventInfo() const {

    std::cout << "Выступления:" << std::endl;
    for (const auto& event : events) {
        std::cout << "--------------------" << endl;
        std::cout << " " << event->getTime() << std::endl;
        std::cout << " " << event->getDate() << std::endl;
        
        std::cout << " " << event->getTitle() << std::endl;
        std::cout << "--------------------" << endl;
    }
}
void Conference::printAdminInfo() const {

    std::cout << "Администраторы:" << std::endl;
    for (const auto& admin : administration) {
        std::cout << "--------------------" << endl;
        std::cout << " " << admin->getFullName() << std::endl;
        std::cout << " " << admin->getPosition() << std::endl;
        std::cout << " " << admin->getResponsibility() << std::endl;
        std::cout << "--------------------" << endl;
    }
}
void Conference::printSpeakerInfo() const {

    std::cout << "Спикеры:" << std::endl;
    for (const auto& speaker : speakers) {
        std::cout << "--------------------" << endl;
        std::cout << " " << speaker->getFullName() << std::endl;
        std::cout << " " << speaker->getOrganization() << std::endl;
        std::cout << " " << speaker->getPresentationTitle() << std::endl;
        std::cout << " " << speaker->getPresentationAbstract() << std::endl;
        std::cout << "--------------------" << endl;
    }
}

void Conference::saveToFile(std::ofstream& file) const {
    
    if (file.is_open()) {
        file << speakers.size() << "\n";
        for (const auto& speaker : speakers) {
            speaker->saveToFile(file);
        }

        file << administration.size() << "\n";
        for (const auto& admin : administration) {
            admin->saveToFile(file);
        }

        file << events.size() << "\n";
        for (const auto& event : events) {
            event->saveToFile(file);
        }

        file.close();
    }
    else {
        std::cerr << "Error: Unable to open file for writing in Conference::saveToFile.\n";
    }
}

void Conference::loadFromFile(std::ifstream& file) {
    if (file.is_open()) {
        // Освобождаем память от текущих элементов, если они есть
        for (auto speaker : speakers) {
            delete speaker;
        }
        speakers.clear();

        for (auto admin : administration) {
            delete admin;
        }
        administration.clear();

        for (auto event : events) {
            delete event;
        }
        events.clear();

        // Загружаем новые элементы из файла
        std::string line;
        std::getline(file, line);
        size_t speakerCount = std::stoi(line);
        for (size_t i = 0; i < speakerCount; ++i) {
            Speaker* speaker = new Speaker();
            speaker->loadFromFile(file);
            speakers.push_back(speaker);
        }

        std::getline(file, line);
        size_t adminCount = std::stoi(line);
        for (size_t i = 0; i < adminCount; ++i) {
            Administration* admin = new Administration();
            admin->loadFromFile(file);
            administration.push_back(admin);
        }

        std::getline(file, line);
        size_t eventCount = std::stoi(line);
        for (size_t i = 0; i < eventCount; ++i) {
            Event* event = new Event();
            event->loadFromFile(file);
            events.push_back(event);
        }

        file.close();
    }
    else {
        std::cerr << "Error: Unable to open file for reading in Conference::loadFromFile.\n";
    }
}

