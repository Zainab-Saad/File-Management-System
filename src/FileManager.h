// -- TODO -- search for existing file/directory only at specified path

#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
#include"Directory.h"
#define SIZE 10
using namespace std;

class FileManager
{
    // root directory
    Directory* rootDirectory;       

    public:
    // constructor 
    FileManager()
    {   
        // make the root directory 
        rootDirectory = new Directory();
        rootDirectory->setDirectoryName("/");
    }
    // destructor
    ~FileManager()
    {
        // *** TODO ***
        // de-allocate the memory and tree here 
        delete rootDirectory;
    }

    // methods for the fileManager
    void createFile(string);                                 // method to create a new file   
    void deleteFile(string);                                // method to delete a file
    void createDirectory(string);                            // method to create a directory
    void deleteDirectory(string);                            // method to delete a directory
    void recurShowDirectory(Directory*);                    // method to recursively show all the directories
    void recurShowTree(Directory*, int depth); 
    void writeToFile(string);                                // method to write to a file
    void readFromFile(string);                               // method to read from a file
    void showTree();                                         // method to show the whole tree
    vector<string> parse (string path);                      // method to parse the path into directories
};

// Method to create a file by passing in the complete file path
void FileManager::createFile(string path)
{
    // vector to create the file at the given path
    vector<string> strings = parse(path);
    // now we have names of individual directories of the root / directory
    Directory* currentDirectory = rootDirectory;
    // to store files in each directory
    vector<File*> files = rootDirectory->getFiles();
    vector<Directory*> directories = rootDirectory->getDirectories();

    // for each directory see, if directory already exists, else make a new directory
    // iterating over all the dirs of the path stored in the vector
    for(auto newDir:strings)          
    {
        //bool fileFound = false;
        bool fileAlreadyExists = false;
        bool dirFound = false;

        /*** checking if directory with that name exists ***/
        // when the target file has been reached at the path
        if(newDir == strings[strings.size()-1])
        {
            // iterate over each file inside the parent directory
            for(auto it : files)
            {
                // if a subdirectory with the a directory name already exists at the required path
                if(it->getFileName() == newDir)
                {
                    cout<<"File with name "<<newDir<<" already exists, can't create directory"<<endl;
                    fileAlreadyExists = 1;
                    break;
                }
            }
            
            // creating a new file only if the file doesn't already exist
            if(!fileAlreadyExists)
            {
                // creating a new directory
                File* newFileCreated = new File();
                // setting the new directory name (the last dir name in the path)
                newFileCreated->setFileName(newDir);
                // put the directory in the vector of its parent directory
                currentDirectory->addFile(newFileCreated);
                cout<<"file created: /"<<path<<endl;
                break;
            } 
        }

        // iterating over all the existing subdirectories in the current directory
        for(auto existingDir : directories)
        {
            // setting the current directory equal to a existing subdir
            currentDirectory = existingDir;
            // if the current subdir is the same as the dir specified in the path, then that dir is found
            if (existingDir->getDirectoryName() == newDir)
            {
                // to store subdirs of the found dir from the path
                directories = existingDir->getDirectories();
                dirFound = true;                // that directory is found
                break;
            }
        }

        // if a directory from the path wasn't found
        if (!dirFound)
       {
            cout<<"Directory "<<newDir<<" doesn't exist"<<endl;
            break;
        }

        // if the file already exists
        if(fileAlreadyExists)
        {
            cout<<"File already exists"<<endl;
            break;    
        }
    }    
}

/*
// Method to delete a file by passing in the complete file path
void FileManager::deleteFile(string path)
{
    // vector to create the file at the given path
    vector<string> strings = parse(path);
    // now we have names of individual directories of the root / directory
    Directory* dir = rootDirectory;
    // to store files in each directory
    vector<File*> files = rootDirectory->getFiles();
    vector<Directory*> directories = rootDirectory->getDirectories();

    // for each directory see, if directory already exists, else make a new directory
    // iterating over all the dirs of the path stored in the vector
    for(auto newDir:strings)          
    {
        bool fileExists = false;
        bool dirFound = false;
        bool fileDeleted = false;

        // when the target file has been reached at that path
        if(newDir == strings[strings.size()-1])
        {
            // iterate over each file inside the parent directory
            for (auto it : files)
            {
                // if a subdirectory with the the file name already exists at the required path
                if(it->getFileName() == newDir)
                {
                    fileExists = true;
                    dir->deleteFile(it);
                    fileDeleted = true;
                    return;
                }
            }
        }

        // iterating over all the existing subdirectories in the current directory
        for(auto directory : directories)
        {
            // setting the current directory equal to a existing subdir
            dir = directory;
            // if the current subdir is the same as the dir specified in the path, then that dir is found
            if (directory->getDirectoryName() == newDir)
            {
                // to store subdirs of the found dir from the path
                directories = directory->getDirectories();
                dirFound = true;                // that directory is found
                break;
            }
        }

        // if a directory from the path wasn't found
        if (!dirFound)
       {
            cout<<"Directory "<<newDir<<" doesn't exist"<<endl;
            break;
        }

        // if the file doesnt exist
        if(!fileExists)
        {
            cout<<"File doesn't exists"<<endl;
            break;    
        }
    } 
}
*/

void FileManager::deleteFile(string paths)
{
    vector<string> strings = parse(paths);
    Directory *dir = rootDirectory;
    File* f;
    vector<File*> files = dir->getFiles();
    vector<Directory*> directories = dir->getDirectories();
    bool fileFound = false, dirFound;
    int index;

    for(auto path : strings)
    {
        dirFound = false;
        // if path leading to the file has been reached
        // now searching for the file
        if (path == strings[strings.size()-1])
        {
            index = 0;
            for (auto file:files)
            {
                // if file is found
                if (path == file->getFileName())
                {
                    fileFound = true;
                    dir->deleteFile(file);
                    break;
                }
                index++;
            }
        }

        for (auto directory:directories)
        {
            // if directory from the path has been found
            if (path == directory->getDirectoryName())
            {
                dirFound = true;
                dir = directory;
                directories = dir->getDirectories();
                files = dir->getFiles();
                break;
            }
        }

        if (fileFound)
        {
            cout<<"file has been deleted"<<endl;
            break;
        }
        if (!dirFound)
        {
            cout<<"Path does not exist"<<endl;
            break;
        }
    }
    if (!fileFound)
        cout<<"File not found"<<endl;
}

// method to create a directory by passing it the complete path
void FileManager::createDirectory(string path)
{
    // vector to store the directories in the path
    vector<string> strings = parse(path);

    // now we have names of individual directories of the root / directory
    Directory* currentDirectory = rootDirectory;
    vector<Directory*> directories = rootDirectory->getDirectories();

    // for each directory see, if directory already exists, else make a new directory
    for(auto newDir:strings)          // iterating over all the dirs of the path stored in the vector
    {
        bool dirFound = false;
        bool dirAlreadyExists = false;

        /*** checking if directory with that name exists ***/
        // when the immediate parent directory has been reached (directory at second last index of vector)
        if(newDir == strings[strings.size()-1])
        {
            // iterate over each subdirectory inside the current directory
            for(auto it : directories)
            {
                // if a subdirectory with the a directory name already exists at the required path
                if(it->getDirectoryName() == newDir)
                {
                    cout<<"Directory with name "<<newDir<<" already exists, can't create directory"<<endl;
                    dirAlreadyExists = 1;
                    break;
                }
            }

            // creating a new directory only if a directory with the same name doesn't already exist
            if(!dirAlreadyExists)
            {
                // creating a new directory
                Directory* newDirectoryCreated = new Directory();
                // setting the new directory name (the last dir name in the path)
                newDirectoryCreated->setDirectoryName(newDir);
                // put the directory in the vector of its parent directory
                currentDirectory->addDirectory(newDirectoryCreated);
                cout<<"path created: /"<<path<<endl;
                break;
            } 
        }

        // iterating over all the existing subdirectories in the current directory
        for(auto existingDir : directories)
        {
            // setting the current directory equal to a existing subdir
            currentDirectory = existingDir;
            // if the current subdir is the same as the dir specified in the path, then that dir is found
            if (existingDir->getDirectoryName() == newDir)
            {
                // to store subdirs of the found dir from the path
                directories = existingDir->getDirectories();
                dirFound = true;                // that directory is found
                break;
            }
        }

        // if a directory from the path wasn't found
        if(!dirFound)
        {
            cout<<"Directory "<<newDir<<" doesn't exist"<<endl;
            break;
        }

        // if the dir already exists at that path
        if(dirAlreadyExists)
            break;    
    }
}

// method to delete a directory by passing it the complete path
void FileManager::deleteDirectory(string path)
{
    // vector to store the dirs in the path by parsing the path
    vector<string> strings = parse(path);
    // intializing current directory at root
    Directory* currentDirectory = rootDirectory;
    // initializing vector of subdirectories to the subdirectories of the root
    vector<Directory*> directories = rootDirectory->getDirectories();

    // iterating over each directory in the path
    for(auto it : strings)
    {
        bool dirFound = 0;
        bool dirDeleted = 0;
        // iterating over the subdirs in the current vector of subdirs
        for(auto dir : directories)
        {
            // if the dir from the path matches the current subdir
            if(dir->getDirectoryName() == it)
            {
                // if the next dir in the path is destination
                if(it == strings[strings.size()-1])
                {
                    // delete the directory
                    currentDirectory->deleteDirectory(dir);
                    dirDeleted = 1; 
                    break;
                }
            /*   **********************   */
                currentDirectory = dir;
                directories = dir->getDirectories();
                dirFound = 1;
                break;
            }
        }
        if(dirDeleted)
        {
            cout<<path<<" has been deleted"<<endl;
            break;
        }

        if(!dirFound)
        {
            cout<<"Cannot delete directory; No directory found"<<endl;
            break;
        }
    }
}

// method to show the hierarchy of the tree structure of directories and files
void FileManager::showTree()
{
    cout<<"Showing the tree"<<endl;
    cout<<"-root"<<endl;
    recurShowTree(rootDirectory, 0);
}

void FileManager::recurShowTree(Directory* curr, int depth)
{
    // to store the subdirectories of the current directory
    vector<Directory*> directories;
    // to store files in the current directory
    vector<File*> files;

    // if the directory contains subdirectories
    if (curr->getDirectories().size() != 0 || curr->getFiles().size() != 0)
    {
        // store the subdirectories in a vector
        directories = curr->getDirectories();
        files = curr->getFiles();
        depth++;
        for (auto file:files)
                cout<<setw(4*depth)<<"*"<<file->getFileName()<<endl;
        // iterating over each subdirectory in the current directory
        for (auto directory : directories)
        {
            cout<<setw(4*depth)<<"-"<<directory->getDirectoryName()<<endl;
            //cout<<"   ";
            recurShowTree(directory, depth);
        }
    }
}

// ---- TO DELETE ----
// recursively show the subdirs in each dir
void FileManager::recurShowDirectory(Directory* currentDirectory)
{
    for(auto it : currentDirectory->getDirectories())
    {
        cout<<"Directory: "<<it->getDirectoryName()<<endl;
        recurShowDirectory(it);
        for (auto file : currentDirectory->getFiles())
            cout<<"file: "<<file->getFileName()<<endl;
    }
}

// method to write content to the file
void FileManager::writeToFile(string filePath)
{
    bool fileFound = false;
    string content;                     // string to store the content

    // parsing the path into separate directories
    vector<string> strings = parse(filePath);
    // initializing current directory at root
    Directory* currentDirectory = rootDirectory;
    // intializing vector of subdirectories to the subdirs of the root
    vector<Directory*> directories = rootDirectory->getDirectories();
    // initializing vector of files in a directory
    vector<File*> files = rootDirectory->getFiles();

    // iterating over each directory in the path
    for (auto newDir : strings)
    {
        bool dirFound = false;

        // when the filename has been reached
        if (newDir == strings[strings.size()-1])
        {
            for (auto file:files)
            {
                if (file->getFileName() == newDir)
                {
                    fileFound = true;
                    cout<<"Write To file "<<newDir<<endl;
                    getchar();
                    // taking the content to write to file from user
                    getline(cin, content);              
                    // dividing the content into blocks
                    for(int len = 0; len<content.length(); len=len+SIZE)
                    {
                        int temp = len;
                        // assuming we start with an empty file each time (for now)
                        // creating and filling the head
                        if (!file->head)
                        {
                            file->head = new Memory::Block();
                            // placing first SIZE (10) characters in the head block
                            for (int i=0; i<SIZE; i++)
                            {
                                file->head->s[i] = content[temp++];
                            }
                            file->head->next = nullptr;
                        }
                        else
                        {
                            Memory::Block *block = new Memory::Block();
                            block->next = nullptr;
                            // placing next SIZE characters in a new block
                            for (int i=0; i<SIZE; i++)
                            {
                                block->s[i] = content[temp++];
                            }
                            cout<<endl;
                            // iterating to the end of the list of blocks to append the last block
                            Memory::Block *ptr = file->head;
                            while(ptr->next != nullptr)
                            {
                                ptr = ptr->next;
                                cout<<"TWO"<<endl;
                            }
                            ptr->next = block;
                            ptr->next->next = nullptr;
                            cout<<ptr<<" "<<ptr->next<<endl;
                        }
                    }
                    return;
                }
            }
        }

        // iterating over all the subdirs of the current dir
        for (auto existingDir:directories)
        {
            // setting current directory equal to each of the subdirs in it
            currentDirectory = existingDir;
            // If the currentDir is the same as a dir specified in the path
            if (existingDir->getDirectoryName() == newDir)
            {
                // storing the subdirs of currentDir in directories vector
                directories = existingDir->getDirectories();
                files = existingDir->getFiles();
                dirFound = true;
                break;
            }
        }
        // if a dir in the path doesnt exist
        if (!dirFound)
        {
            cout<<"Path does not exist"<<endl;
            break;
        }
    }

    // if the file wasn't found
    if (!fileFound)
        cout<<"File does not exist"<<endl;
}

// method to read content from a file
void FileManager::readFromFile(string filePath)
{
    bool fileFound = false;

    // parsing the path into separate directories
    vector<string> strings = parse(filePath);
    // initializing current directory at root
    Directory* currentDirectory = rootDirectory;
    // intializing vector of subdirectories to the subdirs of the root
    vector<Directory*> directories = rootDirectory->getDirectories();
    // initializing vector of files in a directory
    vector<File*> files = rootDirectory->getFiles();

    // iterating over each directory in the path
    for (auto newDir : strings)
    {
        bool dirFound = false;

        // when the filename has been reached
        if (newDir == strings[strings.size()-1])
        {
            for (auto file:files)
            {
                if (file->getFileName() == newDir)
                {
                    fileFound = true;
                    Memory::Block *fileptr = file->head;
                    cout<<"Reading from file "<<newDir<<endl;
                    // reading the content from memory blocks of file
                    while(fileptr)
                    {
                        for (int i=0; i<SIZE; i++)
                            cout<<fileptr->s[i];
                        fileptr = fileptr->next;
                    }
                }
            }
            return;
        }


        // iterating over all the subdirs of the current dir
        for (auto existingDir:directories)
        {
            // setting current directory equal to each of the subdirs in it
            currentDirectory = existingDir;
            // If the currentDir is the same as a dir specified in the path
            if (existingDir->getDirectoryName() == newDir)
            {
                // storing the subdirs of currentDir in directories vector
                directories = existingDir->getDirectories();
                files = existingDir->getFiles();
                dirFound = true;
                break;
            }
        }
        // if a dir in the path doesnt exist
        if (!dirFound)
        {
            cout<<"Path does not exist"<<endl;
            break;
        }
    }
}

vector<string> FileManager:: parse (string path)
{
    vector<string> strings;

    int startIndex = 0, endIndex = 0;

    // iterating over all the characters in the path to parse it
    for (int i = 0; i <= path.size(); i++) 
    { 
        // On reaching the delimiter (/), separate the directories inside the path
        // OR
        // On reaching the end of the path
        if (path[i] == '/' || i == path.size()) 
        {
            endIndex = i;              // storing the index of where one directory ends in the path
            string temp;               // storing information of next dir in path
            // storing (whole path, start index of current dir, size of current dir)
            temp.append(path, startIndex, endIndex - startIndex);
            // and appending to the vector containing the directories of the path
            strings.push_back(temp);
            // start of next directory
            startIndex = endIndex + 1;
        }
    }
    return strings;   
}