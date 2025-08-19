#include "taskManager.h"
#include<iostream>
#include<fstream>

TaskManager::TaskManager() {
    taskCount=0;
    tasks = new Task[]();
}
TaskManager::~TaskManager() {
    delete[] tasks;
}
void TaskManager::CreateTask() {
    Task* prevTaskArr = tasks;
    taskCount++;
    tasks = new Task[taskCount];
    for (int i=0;i<taskCount-1;i++) {
        tasks[i] = prevTaskArr[i];
    }

    std::string name,description;
    std::cout<<"Enter task name: ";
    std::cin>>name;
    std::cout<<"Enter task description: ";
    std::cin>>description;
    tasks[taskCount-1] = Task(name,description);

    std::cout<<"Task("<<name<<":"<<description<<") created successfully with id "<<taskCount<<std::endl;
}
void TaskManager::CreateTask(std::string name, std::string description) {
    Task* prevTaskArr = tasks;
    taskCount++;
    tasks = new Task[taskCount];
    for (int i=0;i<taskCount-1;i++) {
        tasks[i] = prevTaskArr[i];
    }

    tasks[taskCount-1] = Task(name,description);
}

Task* TaskManager::GetAllTasks() {
    return tasks;
}
void TaskManager::DeleteTask(int id) {
    Task* prevTaskArr = tasks;
    tasks = new Task[--taskCount];
    for (int i=0;i<taskCount;i++) {
        tasks[i] = prevTaskArr[i];
        if (i>=id)
            tasks[i] = prevTaskArr[i+1];
    }
}
void TaskManager::SaveOnFile(std::string fileName) {
    std::ofstream out(fileName);
    if (out.is_open()) {
        for (int i=0;i<taskCount;i++) {
            std::string* infoArr = tasks[i].getTaskInfo();
            out << infoArr[0] << " " << infoArr[1] << std::endl;
        }
    }
    else
        std::cout<<"Unable to open file "<<fileName<<std::endl;
}
void TaskManager::LoadFromFile(std::string fileName) {
    std::ifstream in(fileName);
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            std::cout<<line<<std::endl;
            std::string delim(" ");
            size_t prev = 0;
            size_t next;
            size_t delta = delim.length();

            while( ( next = line.find( delim, prev ) ) != std::string::npos ){
                std::string tmp = line.substr( prev, next-prev );
                CreateTask(line.substr(prev,next-prev ), line.substr(next-prev+delta));
                prev = next + delta;
            }
        }
    } else
        std::cout << "Unable to open file " << fileName << std::endl;
}

int TaskManager::GetTaskCount() {
    return taskCount;
}
