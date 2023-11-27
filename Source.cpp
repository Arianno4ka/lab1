#include "conference.h"
#include <iostream>

int main() {
    // Пример использования классов

    // Создаем объект конференции
    Conference conference;

    // Добавляем выступающих
    Speaker speaker1("John Doe", "University A", "Topic 1", "Abstract 1");
    Speaker speaker2("Jane Doe", "Company B", "Topic 2", "Abstract 2");
    conference.addSpeaker(speaker1);
    conference.addSpeaker(speaker2);

    // Добавляем администрацию
    Administration admin1("Admin 1", "Organizer", "Logistics");
    Administration admin2("Admin 2", "Coordinator", "Public relations");
    conference.addAdministration(admin1);
    conference.addAdministration(admin2);

    // Сохраняем конференцию в файл
    conference.saveToFile("conference_data.txt");

    // Загружаем конференцию из файла
    Conference loadedConference;
    loadedConference.loadFromFile("conference_data.txt");

    // Пример вывода информации о загруженной конференции
    std::cout << "Loaded Conference Information:\n";
    // Ваш код вывода информации о конференции...

    return 0;
}
