//implementation of IO.hpp
#include<iostream>
#include "IO.hpp"
#include<fstream>
using namespace std;

IO::IO(const string &file_path){//define constructor,object create hone pe called
    // file_stream.open()->constructor jo file read karega vo file_stream variable mein store kar dega 
    file_stream.open(file_path, ios::in | ios::out | ios::binary);
    // The open member function of the std::fstream class, which opens the file specified by file_path with the given mode
    // ios::in: Open the file for reading.
    // ios::out: Open the file for writing.
    // ios::binary: Open the file in binary mode, which means the data is read or written in binary form
    // The ios::binary flag ensures that the file is treated as a binary file. This is essential when dealing with non-text data, such as images or custom binary formats, where you need to preserve the exact byte values.
    if(!file_stream.is_open()){
        cout<<"Unable to open the file: "<<file_path<<endl;
    }
}

fstream IO::getFileStream(){
    return std::move(file_stream);//file stream return kari hai,move see in unique pointers
}
// Using std::move and returning by value can be useful in scenarios where you need to transfer ownership of the resource, ensuring that only one object manages the resource at any time.

//destructor
IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}