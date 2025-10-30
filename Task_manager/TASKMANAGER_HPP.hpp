#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "Task.hpp"
#include <vector>
#include <string>

class TaskManager {
private:
    std::vector<Task> tasks;
    std::string filename;

public:
    TaskManager(const std::string& file);

    void addTask(const std::string& title);
    void viewTasks() const;
    void markTaskCompleted(int index);

    void loadFromFile();
    void saveToFile() const;
};

#endif
