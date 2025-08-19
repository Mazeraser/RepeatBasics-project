#pragma once
#include "task.h"
#include <string>

class TaskManager {
private:
    int taskCount;
    Task* tasks;
public:
    TaskManager();
    ~TaskManager();
    void CreateTask();
    void CreateTask(std:: string name, std:: string description);
    Task* GetAllTasks();
    void DeleteTask(int id);
    int GetTaskCount();

    void SaveOnFile(std::string fileName);
    void LoadFromFile(std::string fileName);
};