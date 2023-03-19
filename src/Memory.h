#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>
#define SIZE 10
using namespace std;

class Memory
{
    public:
    // structure to hold blocks of content
    struct Block
    {
        char s[SIZE];            // to store the content of the file in blocks
        Block *next;            // pointer to the next block
    };                     

    // constructor
    Memory()
    {
    }
    // destructor
    ~Memory()
    {
        
    }
};

/*
void Memory::storeContent(string content, Memory::Block *ptr)
{

}
*/