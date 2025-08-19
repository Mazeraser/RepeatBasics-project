#include "task.h"

Task::Task() {
    taskName = "";
    taskDescription = "";
}
Task::Task(std::string task_name, std::string task_description) {
    taskName = task_name;
    taskDescription = task_description;
}
Task::~Task() {
}
std::string* Task::getTaskInfo() {
    std::string* result = new std::string[2]();
    result[0] = taskName;
    result[1] = taskDescription;
    return result;
}

