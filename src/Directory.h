#include<vector>
#include"File.h"
using namespace std;

class Directory{
    string name;
    vector<Directory*> directories; vector<File*> files;
public:
    Directory(){

    }
    ~Directory(){
        for(auto it: directories){
            delete it;
        }
        for(auto it : files){
            delete it;
        }
    }
    void setDirectoryName(string);
    string getDirectoryName();
    vector<Directory*> getDirectories();
    vector<File*> getFiles();
    void addDirectory(Directory*);
    void addFile(File*);
    void deleteDirectory(Directory*);
};

void Directory::setDirectoryName(string directoryName){
    this->name = directoryName;
}

string Directory::getDirectoryName(){
    return this->name;
}

vector<Directory*> Directory::getDirectories(){
    return directories;
}

void Directory::addDirectory(Directory* newDirectory){
    directories.push_back(newDirectory);
}

void Directory::deleteDirectory(Directory* directoryToBeDel){
    int count = 0;
    vector<Directory*>::iterator it1;
    for(auto it : directories){
        if(it->getDirectoryName() == directoryToBeDel->getDirectoryName()){
            break;
        }
        count++;
    }
    it1 = directories.begin()+count;
    directories.erase(it1);
}