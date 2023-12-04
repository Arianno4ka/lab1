#ifndef EVENT_H
#define EVENT_H

#include "base.h"
#include <fstream>
#include <string>

class Event : public Base {
private:
    std::string time;
    std::string date;
    std::string title;

public:
    Event();
    Event(const std::string& time, const std::string& date, const std::string& title);
    Event(const Event& other);
    ~Event() override;

    const std::string& getTime() const;
    const std::string& getDate() const;
    const std::string& getTitle() const;

    void setTime(const std::string& newtime);
    void setDate(const std::string& newdate);
    void setTitle(const std::string& newtitle);
   


    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

#endif // EVENT_H
