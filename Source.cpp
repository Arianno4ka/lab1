#include "conference.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    Conference conference; // ������� ������ �����������

    char choice;

    while (true) {
        // ������� ����� ����
        
        std::cout << "===== ���� =====" << std::endl;
        std::cout << "1. �������� �����������" << std::endl;
        std::cout << "2. ���������� �����������" << std::endl;
        std::cout << "3. ������� �����������" << std::endl;
        std::cout << "4. �������� ��������������" << std::endl;
        std::cout << "5. ���������� ��������������" << std::endl;
        std::cout << "6. ������� ��������������" << std::endl;
        std::cout << "7. �������� �������" << std::endl;
        std::cout << "8. ���������� �������" << std::endl;
        std::cout << "9. ������� �������" << std::endl;
        std::cout << "l ���������" << std::endl;
        std::cout << "s ���������" << std::endl;
        std::cout << "0. ����� �� ���������" << std::endl;

        // ����������� ����� ������������
        
        std::cout << "������� ����� ��������� �����: ";
        
        std::cin >> choice;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // ������������ ����� ������������
        switch (choice) {

        case '1': {
            // �������� �����������
            Event newEvent;
            std::cout << "������� ����� �����������: ";
            string time;

            std::getline(std::cin, time);
            newEvent.setTime(time);
            std::cout << "������� ���� �����������: ";
            string date;
            //std::cin.ignore(numeric_limits<streamsize>::max()); // ������� ����� �����
            std::getline(std::cin, date);
            newEvent.setDate(date);

            

            std::cout << "������� �������� �����������: ";
            
            
            string title;
            
            std::getline(std::cin, title);
            newEvent.setTitle(title);

            conference.addEvent(newEvent);
            break;
        }
        case '2':
            // ���������� �����������
            conference.printEventInfo();
            break;
        case '3': {
            // ������� �����������
            std::cout << "������� �������� ����������� ��� ��������: ";
            //std::cin.ignore(); // ������� ����� �����
            string title;
            std::getline(std::cin, title);
            conference.removeEvent(title);
            break;
        }
        case '4': {
            // �������� ��������������
            Administration newAdmin;

            std::cout << "������� ������ ��� ��������������: ";
            std::string fullName;
            //std::cin.ignore(); // ������� ����� �����
            std::getline(std::cin, fullName);
            newAdmin.setFullName(fullName);

            std::cout << "������� ��������� ��������������: ";
            std::string position;
            std::getline(std::cin, position);
            newAdmin.setPosition(position);

            std::cout << "�������  ���� ��������������� ��������������: ";
            std::string responsibility;
            std::getline(std::cin, responsibility);
            newAdmin.setResponsibility(responsibility);

            conference.addAdministration(newAdmin);
            break;
        }
        case '5':
            // ���������� ���������������
            conference.printAdminInfo();
            break;
        case '6': {
            // ������� ��������������
            std::cout << "������� ��� �������������� ��� ��������: ";
            //std::cin.ignore(); // ������� ����� �����
            string name;
            std::getline(std::cin, name);
            conference.removeAdministration(name);
            break;
        }
        case '7': {
            // �������� �������
            Speaker newSpeaker;
            std::cout << "������� ������ ��� �������: ";
            std::string fullName;
            //std::cin.ignore();
            std::getline(std::cin, fullName);
            newSpeaker.setFullName(fullName);

            std::cout << "������� ����������� �������: ";
            std::string organization;
            std::getline(std::cin, organization);
            newSpeaker.setOrganization(organization);

            std::cout << "������� ���� ����������� �������: ";
            std::string presentationTitle;
            std::getline(std::cin, presentationTitle);
            newSpeaker.setPresentationTitle(presentationTitle);

            std::cout << "������� ��������� ����������� �������: ";
            std::string presentationAbstract;
            std::getline(std::cin, presentationAbstract);
            newSpeaker.setPresentationAbstract(presentationAbstract);

            conference.addSpeaker(newSpeaker);
            break;
            
        }
        case '8':
            // ���������� ��������
            conference.printSpeakerInfo();
            break;
        case '9': {
            // ������� �������
            std::cout << "������� ��� ������� ��� ��������: ";
            
            string name;
            std::getline(std::cin, name);
            conference.removeSpeaker(name);
            break;
        }
        case 's': {
            // ��������� ����������� � ����
            std::cout << "������� ��� ����� ��� ���������� �����������: ";
            std::string saveFileName;
            
            std::getline(std::cin, saveFileName);
            //saveFileName = +".txt";
            ofstream ofile(saveFileName);
            conference.saveToFile(ofile);
            break;
        }
        case 'l': {
            // ��������� ����������� �� �����
            std::cout << "������� ��� ����� ��� �������� �����������: ";
            //std::cin.ignore(); // ������� ����� �����
            std::string loadFileName;
            //loadFileName = +".txt";
            std::getline(std::cin, loadFileName);
            ifstream ifile(loadFileName);
            conference.loadFromFile(ifile);
            break;
        }
        case '0':
            std::cout << "��������� ���������." << std::endl;
            return 0;
        default:
            std::cout << "�������� �����." << std::endl;
            break;
        }
    }
}
