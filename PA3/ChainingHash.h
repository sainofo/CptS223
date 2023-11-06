/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
  vector<list<int>> table;
    int tableSize;

    int hashFunction(int key){
        return key % tableSize;
    }

public:
    ChainingHash(int n = 11) {
        tableSize = n;
        table.resize(size);
     }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        int count = -1;
        for(int i = 0; i < tableSize; i++){
            count = table[i].size();
        }
        return -1;
    }

    void operator[](const K& key) {
        int i = -1;
        for(int item = 0; item < table[i]; item++){
            if(item == key){
                return item;
            }
        }
        table[i].push_back(key);
        return -1;
    }

    bool insert(const std::pair<K, V>& pair) {
        const K& key = pair.first;
        int index = hashFunction(key, table.size());

        for(auto& entry : table[index]){
            if(entry.first == key){
                return false;
            }
        }
        table[index].push_back(pair);
        size++;
        return true;
    }

    void erase(const K& key) {
        int i = key % tableSize;
        table[i].remove(key);
    }

    void clear() {
        system("cls");
    }

    int bucket_count() {
        return table.size();
    }

    float load_factor() {
        return static_cast<float>(size) / table.size();
    }


private:

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return 0;       
    }

};

#endif //__CHAINING_HASH_H
