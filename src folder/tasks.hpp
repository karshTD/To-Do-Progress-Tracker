#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <ctime>

class Task {
private:
    std::string title;
    bool completed;
    std::string dateCreated;

    std::string getCurrentDate();

public:
    Task(const std::string& t);
    void markCompleted();
    bool isCompleted() const;
    std::string getTitle() const;
    std::string getDate() const;
    void display() const;
};

#endif
