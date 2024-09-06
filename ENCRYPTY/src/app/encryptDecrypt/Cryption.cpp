 #include "Cryption.hpp"
 #include "../processes/Task.hpp" //task ko deserilize karenge pehle,us se file ka path nikalenge 
 #include "../fileHandling/ReadEnv.cpp"
using namespace std;

 int executeCryption(const string &taskData){
    Task task=Task::fromString(taskData);//deserilaised,fn defined in Task.hpp
    ReadEnv env;

    string envKey=env.getEnv();
    int key=stoi(envKey);//strin to integer bana lenge key ko

    if(task.action==Action::ENCRYPT){
        char ch;  
        while(task.f_stream.get(ch)){//task mein file stream mein ek ek character read karenge(using get)
            ch=(ch+key)%256;//encrpyt ,value 0 to 255 ascii value ke accrding jo bhi character hoga vo aa jayega
            task.f_stream.seekp(-1,ios::cur);//-1->ek step peeche aa jao (seek pointer), make it current position and write there
            //example , "hello world" likha hai, h ke liye $ aaya , pointer e pe aa jayega , to use peeche lao and then write karo at place of h , $
            task.f_stream.put(ch);
        }
        task.f_stream.close();//jab sare charcater encrpyt kar diye ,close
    }
    else{//decrypt
        char ch;
        while(task.f_stream.get(ch)){
            ch=(ch-key+256)%256;
            task.f_stream.seekp(-1,ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }
    return 0;
 }