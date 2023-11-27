#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "base.h"
#include "speaker.h"
#include "administration.h"

class Conference : public Base {
private:
    std::vector<Speaker> speakers;
    std::vector<Administration> administration;
    // Дополнительные данные для программы

public:
    Conference();  // Конструктор по умолчанию
    Conference(const std::vector<Speaker>& speakers, const std::vector<Administration>& administration);
    Conference(const Conference& other);  // Конструктор копирования
    ~Conference() override;  // Деструктор

    void addSpeaker(const Speaker& speaker);
    void removeSpeaker(const std::string& name);  // Предполагаем, что у каждого участника уникальное имя

    void addAdministration(const Administration& admin);
    void removeAdministration(const std::string& name);  // Предполагаем, что у каждого участника уникальное имя

    // Методы для работы с программой

    void saveToFile(const std::string& filename) const override;
    void loadFromFile(const std::string& filename) override;
};

#endif // CONFERENCE_H
