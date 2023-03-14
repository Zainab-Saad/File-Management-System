#include<bits/stdc++.h>
#include"Memory.h"
#include"Directory.h"
using namespace std;

class FileManager{
    Directory* rootDirectory;
    void recurShowDirectory(Directory*);
public:
    FileManager(){     // make the root directory 
        rootDirectory = new Directory();
        rootDirectory->setDirectoryName("/");
    }
    ~FileManager(){
        // deallocate the memory and tree here -- TODO
        delete rootDirectory;
    }
    void createFile(string, string, string);    
    void deletelFile(string);
    void createDirectory(string);
    void deleteDirectory(string);
    void showTree();

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
    // now we have names of individual directories of the root / directory
    Directory* currentDirectory = rootDirectory;
    vector<Directory*> directories = rootDirectory->getDirectories();

    // for each directory see, if directory already exists, else make a new directory
    for(auto newDir : strings){
        bool dirFound = 0;
        bool dirAlreadyExists = 0;
        // check if directory with same name exists -- TODO
        if(newDir == strings[strings.size()-1]){
            for(auto it : directories){
                if(it->getDirectoryName() == newDir){
                    cout<<"Directory with name "<<newDir<<" already exists, can't create directory"<<endl;
                    dirAlreadyExists = 1;break;
                }
            }
            if(!dirAlreadyExists){
                Directory* newDirectoryCreated = new Directory();
                newDirectoryCreated->setDirectoryName(newDir);
                // put the directory in the vector of parent 
                currentDirectory->addDirectory(newDirectoryCreated);
                break;
            }
            
        }
        for(auto existingDir : directories){
            currentDirectory = existingDir;
            if (existingDir->getDirectoryName() == newDir){
                directories = existingDir->getDirectories();
                dirFound = 1;
                break;
            }
        }
        if(!dirFound){
            // make new Directory
            cout<<"Directory "<<newDir<<" doesn't exist"<<endl;
            break;
        }
        if(dirAlreadyExists){
            break;
        }
    }
}

void FileManager::deleteDirectory(string directoryName){
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
    Directory* currentDirectory = rootDirectory;
    vector<Directory*> directories = rootDirectory->getDirectories();
    for(auto it : strings){
        bool dirFound = 0;
        bool dirDeleted = 0;
        for(auto dir : directories){
            if(dir->getDirectoryName() == it){
                // add if here to delete directory TODO
                if(it == strings[strings.size()-1]){
                    // delete the directory
                    currentDirectory->deleteDirectory(dir);
                    dirDeleted = 1; break;
                }
                currentDirectory = dir;
                directories = dir->getDirectories();
                dirFound = 1;
                break;
            }
        }
        if(dirDeleted){
            break;
        }
        if(!dirFound){
            cout<<"Cannot delete directory; No directory found"<<endl;
            break;
        }
    }

}

void FileManager::showTree(){
    cout<<"Showing the directory tree"<<endl;
    cout<<rootDirectory->getDirectoryName()<<endl;
    recurShowDirectory(rootDirectory);
}

void FileManager::recurShowDirectory(Directory* currentDirectory){
    for(auto it : currentDirectory->getDirectories()){
        cout<<"Directory is "<<it->getDirectoryName()<<endl;
        recurShowDirectory(it);
    }
}
