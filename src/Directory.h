#include<vector>
#include"File.h"
using namespace std;

class Directory
{
    string name;                        // string to hold directory name
    vector<Directory*> directories;     // vector to hold sub-directories
    vector<File*> files;

    public:
    Directory()
    { 
        // constructor function 
    }
    // Destructor Function
    ~Directory()
    {
        for(auto it: directories)
        // deleting all directories contained by a Directory object on deletion
            delete it;
        
        for(auto it : files)
        // deleting all directories contained by a Directory object on deletion
            delete it;
        
    }

    void setDirectoryName(string);          // method to set directory name         
    string getDirectoryName();              // method to get directory name
    vector<Directory*> getDirectories();    // method to get subdirectories inside the dir
    vector<File*> getFiles();               // method to get files inside a dir
    void addDirectory(Directory*);          // method to add a subdir
    void addFile(File* newFile);
    void deleteDirectory(Directory*);       // method to delete a subdirectory
    void deleteFile(File*);                 // method to delete a file
};

// function to set name of the Directory
//-------------------------------------------//
void Directory::setDirectoryName(string directoryName){
    this->name = directoryName;
}

// Function to get Directory Name
string Directory::getDirectoryName(){
    return this->name;
}

// Function to get all the SUBdirectories
vector<Directory*> Directory::getDirectories(){
    return directories;
}

// Function to get all the files in a directory
vector<File*> Directory::getFiles(){
    return files;
}

// Function to add a new subdirectory to the directory
void Directory::addDirectory(Directory* newDirectory){
    directories.push_back(newDirectory);
}

// Function to delete a subdirectory
void Directory::deleteDirectory(Directory* directoryToBeDel)
{
    int count = 0;         // variable to hold the index of the subdir to be deleted
    // Iterating over all the subdirectories (it1) inside the Directory's vector and storing it in (it)
    vector<Directory*>::iterator it1;
    for(auto it : directories)
    {
        if(it->getDirectoryName() == directoryToBeDel->getDirectoryName())
        {
            it1 = directories.begin()+count;
            directories.erase(it1);
            break;
        }
        count++;
    }
}

// Function to add a new file to the directory
void Directory::addFile(File* newFile){
    files.push_back(newFile);
}

// Function to delete a file
void Directory::deleteFile(File* file)
{
    int index=0;        // variable to hold index of file to be deleted

    vector<File*>::iterator it1;
    for(auto it : files)
    {
        if(it->getFileName() == file->getFileName())
        {
            it1 = files.begin()+index;
            files.erase(it1);
            break;
        }
        index++;
    }
}

