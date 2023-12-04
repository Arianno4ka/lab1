#include "conference.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    Conference conference; // Создаем объект конференции

    char choice;

    while (true) {
        // Выводим опции меню
        
        std::cout << "===== Меню =====" << std::endl;
        std::cout << "1. Добавить выступление" << std::endl;
        std::cout << "2. Посмотреть выступления" << std::endl;
        std::cout << "3. Удалить выступление" << std::endl;
        std::cout << "4. Добавить администратора" << std::endl;
        std::cout << "5. Посмотреть администратора" << std::endl;
        std::cout << "6. Удалить администратора" << std::endl;
        std::cout << "7. Добавить спикера" << std::endl;
        std::cout << "8. Посмотреть спикера" << std::endl;
        std::cout << "9. Удалить спикера" << std::endl;
        std::cout << "l Загрузить" << std::endl;
        std::cout << "s Сохранить" << std::endl;
        std::cout << "0. Выйти из программы" << std::endl;

        // Запрашиваем выбор пользователя
        
        std::cout << "Введите номер выбранной опции: ";
        
        std::cin >> choice;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Обрабатываем выбор пользователя
        switch (choice) {

        case '1': {
            // Добавить выступление
            Event newEvent;
            std::cout << "Введите время выступления: ";
            string time;

            std::getline(std::cin, time);
            newEvent.setTime(time);
            std::cout << "Введите день выступления: ";
            string date;
            //std::cin.ignore(numeric_limits<streamsize>::max()); // Очищаем буфер ввода
            std::getline(std::cin, date);
            newEvent.setDate(date);

            

            std::cout << "Введите название выступления: ";
            
            
            string title;
            
            std::getline(std::cin, title);
            newEvent.setTitle(title);

            conference.addEvent(newEvent);
            break;
        }
        case '2':
            // Посмотреть выступления
            conference.printEventInfo();
            break;
        case '3': {
            // Удалить выступление
            std::cout << "Введите название выступления для удаления: ";
            //std::cin.ignore(); // Очищаем буфер ввода
            string title;
            std::getline(std::cin, title);
            conference.removeEvent(title);
            break;
        }
        case '4': {
            // Добавить администратора
            Administration newAdmin;

            std::cout << "Введите полное имя администратора: ";
            std::string fullName;
            //std::cin.ignore(); // Очищаем буфер ввода
            std::getline(std::cin, fullName);
            newAdmin.setFullName(fullName);

            std::cout << "Введите должность администратора: ";
            std::string position;
            std::getline(std::cin, position);
            newAdmin.setPosition(position);

            std::cout << "Введите  зону ответственности администратора: ";
            std::string responsibility;
            std::getline(std::cin, responsibility);
            newAdmin.setResponsibility(responsibility);

            conference.addAdministration(newAdmin);
            break;
        }
        case '5':
            // Посмотреть администраторов
            conference.printAdminInfo();
            break;
        case '6': {
            // Удалить администратора
            std::cout << "Введите имя администратора для удаления: ";
            //std::cin.ignore(); // Очищаем буфер ввода
            string name;
            std::getline(std::cin, name);
            conference.removeAdministration(name);
            break;
        }
        case '7': {
            // Добавить спикера
            Speaker newSpeaker;
            std::cout << "Введите полное имя спикера: ";
            std::string fullName;
            //std::cin.ignore();
            std::getline(std::cin, fullName);
            newSpeaker.setFullName(fullName);

            std::cout << "Введите организацию спикера: ";
            std::string organization;
            std::getline(std::cin, organization);
            newSpeaker.setOrganization(organization);

            std::cout << "Введите тему презентации спикера: ";
            std::string presentationTitle;
            std::getline(std::cin, presentationTitle);
            newSpeaker.setPresentationTitle(presentationTitle);

            std::cout << "Введите аннотацию презентации спикера: ";
            std::string presentationAbstract;
            std::getline(std::cin, presentationAbstract);
            newSpeaker.setPresentationAbstract(presentationAbstract);

            conference.addSpeaker(newSpeaker);
            break;
            
        }
        case '8':
            // Посмотреть спикеров
            conference.printSpeakerInfo();
            break;
        case '9': {
            // Удалить спикера
            std::cout << "Введите имя спикера для удаления: ";
            
            string name;
            std::getline(std::cin, name);
            conference.removeSpeaker(name);
            break;
        }
        case 's': {
            // Сохранить конференцию в файл
            std::cout << "Введите имя файла для сохранения конференции: ";
            std::string saveFileName;
            
            std::getline(std::cin, saveFileName);
            //saveFileName = +".txt";
            ofstream ofile(saveFileName);
            conference.saveToFile(ofile);
            break;
        }
        case 'l': {
            // Загрузить конференцию из файла
            std::cout << "Введите имя файла для загрузки конференции: ";
            //std::cin.ignore(); // Очищаем буфер ввода
            std::string loadFileName;
            //loadFileName = +".txt";
            std::getline(std::cin, loadFileName);
            ifstream ifile(loadFileName);
            conference.loadFromFile(ifile);
            break;
        }
        case '0':
            std::cout << "Программа завершена." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор." << std::endl;
            break;
        }
    }
}
