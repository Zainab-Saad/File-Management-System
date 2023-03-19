#include"FileManager.h"
using namespace std;
// initialize the FileManager class
FileManager* fileManager = new FileManager();
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
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"|0| Quit                               |"<<endl;
    cout<<"|1| Create File                        |"<<endl;
    cout<<"|2| Delete File                        |"<<endl;
    cout<<"|3| WriteToFile                        |"<<endl;
    cout<<"|4| ReadFromFile                       |"<<endl;
    cout<<"|5| Create Directory                   |"<<endl;
    cout<<"|6| Delete Directory                   |"<<endl;
    cout<<"|7| Show Tree                          |"<<endl;
    cout<<"---------------------------------------"<<endl;

}

// method to get the input of the command from the console
// calls the callFileOperation method which calls the appropriate method of FileManager class
void Console::getCommand(){
    int command;
    string str1;
    vector<string> vec;
    cout<<"Enter the number to the command you need to perform"<<endl;
    cin>>command;
    switch(command)
    {
        case 0:
            exit(1);
            break;
        case 1:
            cout<<"Enter complete file path to create: "<<endl<<"/";
            cin>>str1;
            fileManager->createFile(str1);
            break;
        case 2:
            cout<<"Enter complete file path to delete"<<endl<<"/";
            cin>>str1;
            fileManager->deleteFile(str1);
            break;
        case 3:
            cout<<"Enter complete file path to write to "<<endl<<"/";
            cin>>str1;
            fileManager->writeToFile(str1);
            break;
        case 4:
            cout<<"Enter complete file path to read from: "<<endl<<"/";
            cin>>str1;
            fileManager->readFromFile(str1);
            break;
        case 5:
            cout<<"Enter complete directory path to create: "<<endl<<"/";
            cin>>str1;
            fileManager->createDirectory(str1);
            break;
        case 6:
            cout<<"Enter complete directory path to delete: "<<endl<<"/";
            cin>>str1;
            fileManager->deleteDirectory(str1);
            break;
        case 7:
            fileManager->showTree();
            break;
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
    delete console;
    delete fileManager;
}
