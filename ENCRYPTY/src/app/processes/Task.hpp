#ifndef TASK_HPP
#define TASK_HPP

#include<string>
#include<iostream>
#include<sstream>
#include "../fileHandling/IO.hpp"
using namespace std;

enum class Action{
    ENCRYPT,
    DECRYPT
};//Enums are used to give names to constants, which makes the code easier to read and maintain. Use enums when you have values that you know aren't going to change, like month days, days, colors, deck of cards, etc.
//{ ENCRYPT, DECRYPT }: These are the enumerators or possible values of the Action enum class. In this case, Action can have one of two values: ENCRYPT or DECRYPT.

struct Task{    ///   =====> this will go in queue
    //3 cheeze
    string filePath;
    fstream f_stream;
    Action action;//encrypt ya decrypt

    //constructor
    Task(fstream &&stream,Action act,string filePath): f_stream(move(stream)),action(act),filePath(filePath){}
    //what is the use of && and move ? ya fir u can say I used move command to transfer the ownership of file instead of making copy 
    //The && in the constructor parameter fstream &&stream indicates that the parameter is a rvalue reference. This is a feature introduced in C++11 that allows you to efficiently transfer resources from one object to another
    //In the context of your code, fstream &&stream is likely used to:
//1 Avoid Unnecessary Copies: When an object is passed to the constructor using an rvalue reference, the resources owned by the temporary object can be moved rather than copied.
//2 Improve Performance: Moving resources can significantly improve performance, especially for large objects or those that manage resources.
//  Moving is faster because it just reassigns resource ownership instead of duplicating the actual data.
// Typically used with temporary objects or rvalues, which are objects that are about to be destroyed.
// I got it , hum bhot sari file stream include karenge , to pass by reference nahi kar sakte kyonki fstream mein nayi file aayegi , hume fstream se file copy karni h , pas instead hum file ki owenership hi move kar dete hain

    // TASK KO SERIALIZE AND DESERIALIZE ->
    string toString(){//serialize 
        ostringstream oss;
        oss<<filePath<<","<<(action==Action::ENCRYPT?"Encrypt":"Decrypt");//ternary operator 
        // test.txt ENCRYPT f_stream ,ye function is test file ki string bana raha h like below 
        // "test.txt,ENCRYPT"
        return oss.str();
    } 

    //deserialize
    static Task fromString(const std::string &taskData){
        istringstream iss(taskData);
        string filePath;
        string actionStr;

        //filepath , tak // & comma ke bad jo string bachi h vo actionStr mein
        if(getline(iss,filePath,',') && getline(iss,actionStr)){
            // "test.txt","ENCRYPT"=> yaha first string filePath mein , second actionStr mein 
            Action action = (actionStr=="ENCRYPT"?Action::ENCRYPT:Action::DECRYPT);
            IO io(filePath);//to read file 
            fstream f_stream = move(io.getFileStream());//move the ownership ,dont create unnecessary copy, move its ownership to f_stream
            if(f_stream.is_open()){
                return Task(move(f_stream),action,filePath);
            }
            else{
                throw runtime_error("Failed to open file: "+filePath);
            }
        }else{// deserialize nahi kar pa rahe to 
            throw runtime_error("Invalid task data format");
        }

    }
};



#endif