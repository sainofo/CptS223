#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<list<int>> table;
    int tableSize;

    int hashFunction(int key){
        return key % tableSize;
    }
public:
    ProbingHash(int n = 11) {
        tableSize = n;
        table.resize(size);
    }

    ~ProbingHash() {
        this->clear();
    }

    bool empty(){
        for(int i = 0; i < table.capacity(); i++){
            if(table[i].first != EMPTY){
                return false;
            }
        }
        return true;
    }

    int size() {
        int count  = -1;
        for(int i = 0; i < tableSize; i++){
            count = tableSize[i].size();
        }
        return -1;
    }

    V& at(const K& key){
        int hashkey = hash(key);
        K tempkey = key;

        while(table[hashkey].first != EMPTY){
            if(table[hashkey].second.first == key && table[hashkey].first != DELETED){
                return table[hashkey].second.second;
            }
            tempkey++;
            hashkey = hash(key);
        }
        throw out_of_range("Key is not in hash");
    }

    V operator[](const K& key) {
        return -1;
    }

    int count(const K& key){
        int hashkey = hash(key);
        int keycount = 0;
        int i = 0;

        while(table[hashkey].first != EMPTY){
            if(table[hashkey].second.first == key && table[hashkey].first != DELETED){
                keycount++;
            }
            i++;
            hashkey = hash(key + i);
        }
        return keycount;
    }

    bool insert(const std::pair<K, V>& pair) {
        return true;
    }

    void erase(const K& key) {
        int hashkey = hash(key);
        K tempkey = key;

        while(table[hashkey].first != EMPTY){
            if(table[hashkey].second.first == key){
                table[hashkey].first = DELETED;
                return;
            }
            tempkey++;
            hashkey = hash(tempkey);
        }
        return;
    }

    void clear() {
        for(int i = 0; i < table.capacity(); i++){
            table[i].first = EMPTY;
        }
    }

    int bucket_count() {
        return table.capacity();
    }

    float load_factor() {
        int count = 0;

        for(int i = 0; i < table.capacity(); i++){
            if(table[i].firsy != EMPTY){
                count++;
            }
        }
        float load = count / bucket_count();
    }

    void rehash(){
        tableSize = findNextPrime(2 * bucket_count());
        vector<pair<K,V>> AllValues;

        for(int i = 0; i < table.capacity(); i++){
            if(table[i].first != EMPTY){
                AllValues.push_back(table[i].second);
            }
        }
        
        clear();
        table.resize(tableSize);

        for(pair<K,V> p : AllValues){
            insert(p);
        }
    }

    int rehash(int n){
        tableSize = findNextPrime(n);
        vector<pair<K,V>> AllValues;

        for(int i = 0; i < table.capacity(); i++){
            if(table[i].first != EMPTY){
                AllValues.push_back(table[i].second);
            }
        }

        clear();
        table.resize(tableSize);

        for(pair<K,V> p: AllValues){
            insert(p);
        }
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

#endif //__PROBING_HASH_H
