#include <iostream>
#include <cstring>
#include<string.h>
#define SIZE 10
using namespace std;

class File
{
    // name of the file
    string fileName;
    // structure to hold contents of a file
    struct Block
    {
        char s[SIZE];
        Block *next;
    }*head;

    public:
    // constructor
    File()
    {
        head = NULL;
        cout<<"filename: ";
        cin>>fileName;
        getchar();      // to read the linefeed from the cin
    }

    // function to get the name of the file
    string getName() { return fileName; }

    // function to write content to the file
    void writeToFile()
    {
        string content;
        cout<<"Write to the file"<<endl;
        getline(cin, content);

        // dividing the content into blocks
        for(int len = 0; len<content.length(); len=len+SIZE)
        {
            // assuming we start with an empty file each time (for now)
            // creating and filling the head
            if (!head)
            {
                int temp = len;
                head = new Block();
                head->next = NULL;
                // placing first SIZE (10) characters in the head block
                for (int i=0; i<SIZE; i++)
                    head->s[i] = content[len++];
            }
            else
            {
                Block *block = new Block();
                // placing next SIZE (10) characters in a new block
                for (int i=0; i<SIZE; i++)
                    block->s[i] = content[len++];
                // iterating to the end of the list of blocks to append the latest block
                Block *temp = head;
                while(temp->next)
                    temp = temp->next;
                temp->next = block;
            }
        }
    }  
};

int main ()
{
    // creating an instance of the file
    File file;
    //cout<<file.getName()<<endl;
    // Function to write to the file
    file.writeToFile();
}