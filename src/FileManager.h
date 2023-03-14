#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include"Memory.h"
#include"Directory.h"
using namespace std;

/*
FileManager has pointer to the directories tree 
FUNCTIONS OF FileManager ----
* create file

*/

class FileManager{
    Directory* rootDirectory;
public:
    FileManager(){     // make the root directory 
        rootDirectory = new Directory();
        rootDirectory->setDirectoryName("/");
        cout<<"root Directory is"<<rootDirectory->getDirectoryName(); 
    }
    ~FileManager(){
        // deallocate the memory and tree here -- TODO
    }
    void createFile(string, string, string);    
    void deletelFile(string);
    void createDirectory(string);
    void deleteDirectory(string);

};
// take the file name, content
void FileManager::createFile(string fileName, string directoryName, string fileContent){
    Memory::storeContent(fileContent);
    
    // TODO
    // make a node of file and place in the corect position in tree


    // store the content in a memory block

}

void FileManager::deletelFile(string fileName){
    // TODO
}

void FileManager::createDirectory(string directoryName){
    vector<string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= directoryName.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (directoryName[i] == '/' || i == directoryName.size()) {
            endIndex = i;
            string temp;
            temp.append(directoryName, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    // now we have names of individual directories
    vector<Directory*> directories = rootDirectory->getDirectories();
    
    for(auto it : directories){
        cout<<it;
    }

}

void FileManager::deleteDirectory(string directoryName){
    // TODO
}
