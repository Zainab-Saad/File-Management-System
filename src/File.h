#include<iostream>
#include<string>
using namespace std;

class File{
    string name;
    // pointer to the memory block
public:
    File(){

    }
    ~File(){

    }
    string getFileName();
    void setFileName(string);
};
