#include "graph.hpp"
#include <iostream>

void Graph::showProgress(const std::vector<Task>& tasks) {
    std::map<std::string, int> completedPerDay;

    
    for (const Task& task : tasks) {
        if (task.isCompleted()) {
            completedPerDay[task.getDate()]++;
        }
    }

    if (completedPerDay.empty()) {
        std::cout << "\nNo completed tasks yet.\n";
        return;
    }

    std::cout << "\n===== PROGRESS GRAPH =====\n";

    for (const auto& entry : completedPerDay) {
        std::cout << entry.first << " | ";
        for (int i = 0; i < entry.second; i++) {
            std::cout << "#";
        }
        std::cout << " (" << entry.second << ")\n";
    }
}
