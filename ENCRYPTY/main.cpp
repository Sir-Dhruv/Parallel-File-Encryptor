#include<iostream>
#include<filesystem>
#include "./src/app/processes/ProcessManagement.hpp"
#include "./src/app/processes/Task.hpp"
using namespace std;

int main(int argc,char *argv[]){
    string directory;
    string action;

    cout<<"Enter the directory path: "<<endl;
    getline(cin,directory);

    cout<<"Enter the action (encrypt/decrypt): "<<endl;
    getline(cin,action);

    try{
        if(fs::exists(directory) && fs::is_directory(directory)){
            ProcessManagement ProcessManagement;
            for(const auto &entry: fs::recursive_directory_iterator(directory)){
                if(entry.is_regular_file()){
                    string filePath = entry.path().string();
                    IO io(filePath);
                    fstream f_stream=move(io.getFileStrean());
                    if(f_stream.is_open()){
                        Action taskAction=(action=="ENCRYPT"?Action::ENCRYPT: Action::DECRYPT);
                        auto task=make_unique<Task>(std:move(f_stream),taskAction,filePath);
                        ProcessManagement.submitToQueue(move(task));
                    }
                    else{
                        cout<<"Unable to open the file: "<<filePath<<endl;
                    }
                }
            }
            ProcessManagement.executeTasks();
        }else{
            cout<<"Invalid directory path: "<<endl;
        }
    }
    catch(const fs::filesystem_error &ex){
        cout<<"Filesystem error: "<<ex.what()<<endl;
    }
    
}