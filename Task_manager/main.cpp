#include "TaskManager.hpp"
#include <iostream>

int main() {
    TaskManager manager("tasks.txt");
    int choice;

    while (true) {
        std::cout << "\n===== TASK TRACKER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task Completed\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title;
            std::cout << "Enter task title: ";
            getline(std::cin, title);
            manager.addTask(title);
        }
        else if (choice == 2) {
            manager.viewTasks();
        }
        else if (choice == 3) {
            int index;
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> index;
            manager.markTaskCompleted(index);
        }
        else if (choice == 4) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
