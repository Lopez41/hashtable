/*******************
*coding assignment 07: Hash table
*Name: Adrian Lopez
*Date: 07/04/23
*Status:in progress
*Language: C++
*File: hashtable.h
*******************/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedlist.h"
#define HASHTABLESIZE 15  // The size of the hash table array

class HashTable
{
public:
    //constructor
    HashTable();
    //deconstructor
    ~HashTable();
     
    //methods
   bool insertEntry(int,string*);
   string getData(int);
   bool removeEntry(int);
   int getCount();
   void printTable();



private:
    //private methods
    LinkedList* table;
    int hash(int);

};

#endif