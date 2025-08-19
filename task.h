#pragma once
#include <string>

class Task {
private:
    std::string taskName;
    std::string taskDescription;
public:
    Task();
    Task(std::string task_name, std::string task_description);
    ~Task();
    std::string* getTaskInfo();
};
