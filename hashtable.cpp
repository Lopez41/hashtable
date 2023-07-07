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

  // Clear all the linked lists in the hash table
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        table[i].clearList();
    }

    delete[] table;
}

bool HashTable::insertEntry(int id, string* data) 
{
    int index = hash(id);
    return table[index].addNode(id, data);
}

string HashTable::getData(int id) {
    int index = hash(id);
    Data data;
    if (table[index].getNode(id, &data)) 
    {
        return data.data;
    }
    return "";
}


