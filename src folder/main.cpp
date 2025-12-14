#include <iostream>
#include "TASKMANAGER_HPP.hpp"

int main() {
    TaskManager manager("tasks.txt");
    int choice;

    while (true) {
        std::cout << "\n===== TO DO PROGRESS TRACKER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task Completed\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title;
            std::cout << "Enter task title: ";
            std::getline(std::cin, title);
            manager.addTask(title);
        }
        else if (choice == 2) {
            manager.viewTasks();
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter task number: ";
            std::cin >> id;
            manager.markTaskCompleted(id);
        }
        else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
