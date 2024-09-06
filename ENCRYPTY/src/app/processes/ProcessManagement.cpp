#include "ProcessManagement.hpp"
#include<iostream>
#include<cstring>
#include<sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"
using namespace std;

ProcessManagement::ProcessManagement(){};//constructor

bool ProcessManagement::submitToQueue(unique_ptr<Task> task){
    taskQueue.push(move(task));
    return true;
} 

void ProcessManagement::executeTasks(){//matlab consume karna process queue mein se ,see the initial diagram to understand
    while(!taskQueue.empty()){
        unique_ptr<Task> taskToExecute=move(taskQueue.front());//task to execute is a pointer which is pointing to task
        taskQueue.pop();
        cout<<"Executing task: "<<taskToExecute->toString()<<endl;
        executeCryption(taskToExecute->toString());//takes serialized string and deserializes it 
    }
}