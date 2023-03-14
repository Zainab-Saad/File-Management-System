#include<iostream>
#include<string>
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

    }
    void setDirectoryName(string);
    string getDirectoryName();
    vector<Directory*> getDirectories();
    vector<File*> getFiles();
    void addDirectory(Directory*);
    void addFile(File*);
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
