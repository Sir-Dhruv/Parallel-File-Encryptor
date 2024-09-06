#include<iostream>
#include<string>
#include<fstream>
#include "IO.hpp"
#include<string>
#include<sstream>
using namespace std;

class ReadEnv{
    public:
        string getEnv(){// TO READ THE ENVIRONMENT FILE(KEY h isme)
            string env_path=".env";      
            IO io(env_path);// IO class names io , jisme file path de do,it will return fstream(file open karke de degi)
            //we need fstream only to do any modification in file, like kuch read karne ke liye ya write karne ke liye 
            fstream f_stream=io.getFileStream();//filestream return kar dega

            stringstream buffer;//This line creates a stringstream object named buffer( stringstream: This is a class provided by the <sstream> library in C++. It allows you to create an in-memory stream that can be used both for input and output operations on strings.)
            buffer << f_stream.rdbuf(); // This line reads the entire contents of the f_stream into the buffer stream.
            string content = buffer.str();// converts the contents of the buffer stream into a string 
            // PLEASE TELL THE ABOVE 3 LINES OF CODE IN 3 LINES TO EXPLAIN IN AN INTERVIEW
            // ANSWER==>>
            // These three lines of code read the entire contents of a file into a string. 
            // First, they create an in-memory buffer.
            // Then, they load the file's contents into this buffer. 
            // Finally, they convert the buffer's contents into a string that can be easily used or manipulated in the program.

            return content;

        }
};