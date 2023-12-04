#include "event.h"

Event::Event() {
    // Конструктор по умолчанию
}

Event::Event(const std::string& time, const std::string& date, const std::string& title) : time(time), date(date), title(title) {
    // Конструктор с параметрами
}

Event::Event(const Event& other)
    : time(other.time), date(other.date), title(other.title) {
    // Конструктор копирования
}

Event::~Event() {
    // Деструктор
    std::cout << "Event destructor called.\n";
}

const std::string& Event::getTime() const {
    return time;
}

const std::string& Event::getDate() const {
    return date;
}

const std::string& Event::getTitle() const {
    return title;
}


void Event::setTime(const std::string& newtime) {
    time = newtime;
}

void Event::setDate(const std::string& newdate) {
    date = newdate;
}

void Event::setTitle(const std::string& newtitle) {
    title = newtitle;
}



void Event::saveToFile(std::ofstream& file) const {
    // Реализация сохранения в файл для класса Event
    if (file.is_open()) {
        file << time << "\n";
        file << date << "\n";
        file << title << "\n";
    }
    else {
        std::cerr << "Error: Unable to open file for writing in Event::saveToFile.\n";
    }
}

void Event::loadFromFile(std::ifstream& file) {
    // Реализация загрузки из файла для класса Event
    if (file.is_open()) {
        std::getline(file, time);
        std::getline(file, date);
        std::getline(file, title);
    }
    else {
        std::cerr << "Error: Unable to open file for reading in Event::loadToFile.\n";
    }
}



