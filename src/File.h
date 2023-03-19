#include<iostream>
#include"Memory.h"
#include<string>
using namespace std;

class File
{
    string fileName;
    // pointer to the memory block
    public:
    Memory::Block *head;
    File()
    {
        head = NULL;
    }
    ~File()
    {
        // desrtuctor
    }

    // methods for Files    
    string getFileName();           // method to get the name of the file
    void setFileName(string);       // method to set the name of the file
};

// function to get file name
string File::getFileName()
{
    return fileName;
}


// function to set file name (at creation)
void File::setFileName(string name)
{
    fileName = name;
    cout<<"The name of the file has been set to "<<fileName<<endl;
}

