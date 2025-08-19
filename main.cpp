#include <iostream>

#include "task.h"
#include "taskManager.h"

int main() {
    std::cout
        << "1. Add task\n"
        << "2. View all tasks\n"
        << "3. Delete task\n"
        << "4. Save on file\n"
        << "5. Load from file\n"
        << "6. Exit\n";

    TaskManager taskManager = TaskManager();
    int key;
    while (key!=6) {
        Task* tasks = taskManager.GetAllTasks();
        std::cout << "Select action: ";
        std::cin >> key;
        switch (key) {
            case 1:
                taskManager.CreateTask();
                break;
            case 2:
                for (int i=0;i<taskManager.GetTaskCount();i++) {
                    std::string* arr= tasks[i].getTaskInfo();
                    std::cout << i+1 << "."<<arr[0]<<"-"<<arr[1]<<std::endl;
                }
                break;
            case 3:
                int id;
                std::cout << "Enter task id: ";
                std::cin >> id;
                taskManager.DeleteTask(id-1);
                break;
            case 4:
                taskManager.SaveOnFile("file.txt");
                break;
            case 5:
                taskManager.LoadFromFile("file.txt");
                break;
            default:
                break;
        }
    }
    return 0;
}
