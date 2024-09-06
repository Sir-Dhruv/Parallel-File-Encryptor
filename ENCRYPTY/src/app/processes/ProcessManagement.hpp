#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement{
    public:
        ProcessManagement();//constructor , intialize a queue 
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private: 
        queue<unique_ptr<Task>> taskQueue;  //taskqueue mein unique pointer store kar rahi h task ka  
// unique_ptr: This is a smart pointer that manages ownership of a dynamically allocated object. It ensures that the object is deleted automatically when the unique_ptr goes out of scope.
// <Task>: This indicates that the unique_ptr points to an object of type Task. We assume Task is a user-defined class or struct.
// The line declares a queue named taskQueue that can hold elements of type unique_ptr<Task>.
};


#endif 