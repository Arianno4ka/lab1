#ifndef SPEAKER_H
#define SPEAKER_H

#include "base.h"
#include <fstream>
#include <string>
using namespace std;

class Speaker : public Base {
private:
    std::string fullName;
    std::string organization;
    std::string presentationTitle;
    std::string presentationAbstract;

public:
    Speaker();
    Speaker(const std::string& fullName, const std::string& organization,
        const std::string& presentationTitle, const std::string& presentationAbstract);
    Speaker(const Speaker& other);
    ~Speaker() override;

    const std::string& getFullName() const;
    const std::string& getOrganization() const;
    const std::string& getPresentationTitle() const;
    const std::string& getPresentationAbstract() const;

    void setFullName(const std::string& name);
    void setOrganization(const std::string& org);
    void setPresentationTitle(const std::string& title);
    void setPresentationAbstract(const std::string& abstract);


    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // SPEAKER_H
