#ifndef SPEAKER_H
#define SPEAKER_H

#include "base.h"

class Speaker : public Base {
private:
    std::string fullName;
    std::string organization;
    std::string presentationTitle;
    std::string presentationAbstract;

public:
    Speaker();  // ����������� �� ���������
    Speaker(const std::string& fullName, const std::string& organization,
        const std::string& presentationTitle, const std::string& presentationAbstract);
    Speaker(const Speaker& other);  // ����������� �����������
    ~Speaker() override;  // ����������

    // ������� � ������� ��� ������

    void saveToFile(const std::string& filename) const override;
    void loadFromFile(const std::string& filename) override;
};

#endif // SPEAKER_H
