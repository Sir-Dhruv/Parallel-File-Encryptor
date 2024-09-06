//including header files 
#ifndef IO_HPP // why ifndef , to ensure that the contents of a header file are included only once, even if the header file is included multiple times in different parts of the code(compile ek hi bar hota hai phir, pass by reference ho jati hai fir). This avoids redefinition and reduces compilation time
#define IO_HPP

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

class IO{
    public:
        IO(const string &file_path);//constructor
        //const cause file ka path kabhi bhi change nahi hoga
        ~IO();//destructor
        fstream getFileStream();//getter hai 

    private:
        fstream file_stream;//jab constructor file padh lega, is variable mein usko store kra lega

};



#endif