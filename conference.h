#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "base.h"
#include "speaker.h"
#include "administration.h"

class Conference : public Base {
private:
    std::vector<Speaker> speakers;
    std::vector<Administration> administration;
    // �������������� ������ ��� ���������

public:
    Conference();  // ����������� �� ���������
    Conference(const std::vector<Speaker>& speakers, const std::vector<Administration>& administration);
    Conference(const Conference& other);  // ����������� �����������
    ~Conference() override;  // ����������

    void addSpeaker(const Speaker& speaker);
    void removeSpeaker(const std::string& name);  // ������������, ��� � ������� ��������� ���������� ���

    void addAdministration(const Administration& admin);
    void removeAdministration(const std::string& name);  // ������������, ��� � ������� ��������� ���������� ���

    // ������ ��� ������ � ����������

    void saveToFile(const std::string& filename) const override;
    void loadFromFile(const std::string& filename) override;
};

#endif // CONFERENCE_H
