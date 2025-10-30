#include "TaskManager.hpp"
#include <iostream>
#include <fstream>

TaskManager::TaskManager(const std::string& file) {
    filename = file;
    loadFromFile();
}

void TaskManager::addTask(const std::string& title) {
    tasks.push_back(Task(title));
    saveToFile();
}

void TaskManager::viewTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        tasks[i].display();
    }
}

void TaskManager::markTaskCompleted(int index) {
    if (index < 1 || index > (int)tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markCompleted();
    saveToFile();
}

void TaskManager::loadFromFile() {
    tasks.clear();
    std::ifstream in(filename);
    if (!in.is_open()) return;

    std::string title, status, date;
    while (getline(in, title, '|')) {
        getline(in, status, '|');
        getline(in, date);

        Task t(title);
        if (status == "1") t.markCompleted();
        tasks.push_back(t);
    }
    in.close();
}

void TaskManager::saveToFile() const {
    std::ofstream out(filename);
    for (const auto& t : tasks) {
        out << t.getTitle() << '|'
            << (t.isCompleted() ? "1" : "0") << '|'
            << t.getDate() << '\n';
    }
    out.close();
}
