#include "tasks.hpp"
#include <iostream>
#include <iomanip>

Task::Task(const std::string& t) {
    title = t;
    completed = false;
    dateCreated = getCurrentDate();
}

void Task::markCompleted() {
    completed = true;
}

bool Task::isCompleted() const {
    return completed;
}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDate() const {
    return dateCreated;
}

void Task::display() const {
    std::cout << std::left << std::setw(25) << title 
              << " | " << (completed ? "✅ Done" : "⏳ Pending")
              << " | " << dateCreated << std::endl;
}

std::string Task::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    sprintf(buffer, "%02d-%02d-%04d", ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    return std::string(buffer);
}
