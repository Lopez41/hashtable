/*******************
*coding assignment 07: Hash table
*Name: Adrian Lopez
*Date: 07/04/23
*Status:in progress
*Language: C++
*File: main.cpp
*******************/

#include "main.h"

int main() 
{
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) 
    {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashTable;

    // testing intial hash table
    cout << "Initial Hash Table:" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();
    cout << endl;
// Insert test data into the hash table
    for (int i = 0; i < testdatasize; i++) 
        {
    if (hashTable.insertEntry(ids[i], &strs[i])) 
    {
    cout << "Inserted: " << ids[i] << " : " << strs[i] << endl;
    } else 
    {
    cout << "Failed to insert: " << ids[i] << " : " << strs[i] << endl;
    }
    }
    // testing final hash table 
    cout << endl;
    cout << "Final Hash Table:" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();
    cout << endl;
    // getting data
    cout << "Retrieving Data..." << endl;
    for (int i = 0; i < testdatasize; i++)
    {
        string data = hashTable.getData(ids[i]);
        cout << "Data for " << ids[i] << ": " << (data.empty() ? "Not Found" : data) << endl;
    }
    cout << endl;
   

    return 0;
}



