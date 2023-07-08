/*******************
*coding assignment 07: Hash table
*Name: Adrian Lopez
*Date: 07/04/23
*Status:in progress
*Language: C++
*File: hashtable.cpp
*******************/

#include "hashtable.h"

HashTable::HashTable() 
{
    // Initialize the hash table
     table = new LinkedList[HASHTABLESIZE];
}

HashTable::~HashTable() 
{

    delete[] table;
}

bool HashTable::insertEntry(int id, string* data) 
{
    int index = hash(id);
    return table[index].addNode(id, data);
}

string HashTable::getData(int id) 
{
    int index = hash(id);
    Data data;
    string result = "";  // Initialize an empty string

    if (table[index].getNode(id, &data)) 
    {
        result = data.data;
    }

    return result;
}

bool HashTable::removeEntry(int id)
 {
    int index = hash(id);
    return table[index].deleteNode(id);
}

int HashTable::getCount()
 {
    int count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) 
    {
        count += table[i].getCount();
    }
    return count;
}

void HashTable::printTable()
{
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        std::cout << "Entry " << i << ": ";

        if (table[i].getCount() == 0)
        {
            std::cout << "EMPTY" << std::endl;
        }
        else
        {
            table[i].printList();
        }
    }
}

int HashTable::hash(int id)
{
    return id % HASHTABLESIZE;
}