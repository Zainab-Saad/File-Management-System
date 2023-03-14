#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Memory{
    struct Block{
        char contents[0];
    }*head;
public:
    Memory(){

    }
    ~Memory(){
        
    }
    static void storeContent(string);

};

void Memory::storeContent(string contents){
    // convert the string to character array
    char* contentCharArray = new char[contents.length()+1];
    strcpy(contentCharArray, contents.c_str());
    for (int i = 0; i < contents.length(); i++)
    {
        std::cout << contentCharArray[i];
    }
}