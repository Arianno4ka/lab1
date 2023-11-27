#include "conference.h"
#include <iostream>

int main() {
    // ������ ������������� �������

    // ������� ������ �����������
    Conference conference;

    // ��������� �����������
    Speaker speaker1("John Doe", "University A", "Topic 1", "Abstract 1");
    Speaker speaker2("Jane Doe", "Company B", "Topic 2", "Abstract 2");
    conference.addSpeaker(speaker1);
    conference.addSpeaker(speaker2);

    // ��������� �������������
    Administration admin1("Admin 1", "Organizer", "Logistics");
    Administration admin2("Admin 2", "Coordinator", "Public relations");
    conference.addAdministration(admin1);
    conference.addAdministration(admin2);

    // ��������� ����������� � ����
    conference.saveToFile("conference_data.txt");

    // ��������� ����������� �� �����
    Conference loadedConference;
    loadedConference.loadFromFile("conference_data.txt");

    // ������ ������ ���������� � ����������� �����������
    std::cout << "Loaded Conference Information:\n";
    // ��� ��� ������ ���������� � �����������...

    return 0;
}
