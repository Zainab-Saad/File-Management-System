#include<iostream>
#include<string>
#include<vector>
#include"FileManager.h"
using namespace std;

class Console{
public:
    Console(){

    }
    ~Console(){

    }
    void showCommands(); 
    void getCommand();  
    void callFileOperation(void (*func)(vector<string>), vector<string>);
};
// method to show the menu of commands 
void Console::showCommands(){
    cout<<"---------------------------------------"<<endl;
    cout<<"|0|Quit                               |"<<endl;
    cout<<"|1|Create File                        |"<<endl;
    cout<<"|2|Delete File                        |"<<endl;
    cout<<"|3|Create Directory                   |"<<endl;
    cout<<"|4|Delete Directory                   |"<<endl;
    cout<<"---------------------------------------"<<endl;

}

// method to get the input of the command from the console
// calls the callFileOperation method which calls the appropriate method of FileManager class
void Console::getCommand(){
    // initialize the FileManager class
    FileManager* fileManager = new FileManager();
    int command;
    string str1, str2, str3;
    vector<string> vec;
    cout<<"Enter the number to the command you need to perform"<<endl;
    cin>>command;
    switch(command){
        case 0:
            exit(1);
            break;
        case 1:
            cout<<"Enter file name to create: "<<endl;
            cin>>str1;
            cout<<"Enter the directory name: "<<endl;
            cin>>str2;
            cout<<"Enter file contents: "<<endl;
            str3 = "i am a girl";
            fileManager->createFile(str1, str2, str3);
            break;
        case 2:
            cout<<"Enter file name to delete: "<<endl;
            cin>>str1;
            break;
        case 3:
            cout<<"Enter directory name: \n/";
            cin>>str1;
            fileManager->createDirectory(str1);
        default:
            cout<<"Enter valid command option"<<endl;
    }
}

void Console::callFileOperation(void (*func)(vector<string>), vector<string> args){
    
}


int main(){
    Console* console = new Console();
    while(true){
        console->showCommands();
        console->getCommand();
    }
}



