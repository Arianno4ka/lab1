

#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "base.h"
#include "speaker.h"
#include "administration.h"
#include "event.h"
#include <vector>

class Conference : public Base {
private:
    std::vector<Speaker*> speakers;
    std::vector<Administration*> administration;
    std::vector<Event*> events;

public:
    Conference();
    ~Conference() override;

    void addSpeaker(const Speaker& speaker);
    void addAdministration(const Administration& admin);
    void addEvent(const Event& event);

    void removeSpeaker(const std::string& name);
    void removeAdministration(const std::string& name);
    void removeEvent(const std::string& title);

    void printEventInfo() const;
    void printAdminInfo() const;
    void printSpeakerInfo() const;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // CONFERENCE_H
