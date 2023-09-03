#include <iostream>
#include <list> 
#include <cstring> 
using namespace std ; 

// Hashtable implementation 

class HashTable {
    private: 
        static const int  hashGroups = 10; 
        list<pair<int, string>> table[hashGroups]; 
    
    public:
        bool isEmpty() const; 
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key); 
        string searchItem(int key); 
        void printTable();   
}; 
bool HashTable::isEmpty() const {
        int sum = 0; 
        for(int i = 0;i<hashGroups;i++){
            sum += table[i].size(); 
        }
        if(!sum) return true; 
        return false; 
}
int HashTable::hashFunction(int key){
    return key % hashGroups; 
}
void HashTable::insertItem(int key, string value){
    int hashcode = hashFunction(key);
    auto& cell = table[hashcode]; 
    auto itr = begin(cell); 
    bool keyExists = false; 
    for(; itr != cell.end() ; itr++){
        if(itr->first == key){ // key exists
            keyExists =  true; 
            itr->second =    value ; 
            cout <<  "Key exists. Value replaced" << endl ; 
            break; 
        }
    }
    if(!keyExists){
        cell.emplace_back(key, value);  
    }
    return ; 
}
void HashTable::removeItem(int key)
{
    int hashcode = hashFunction(key);
    auto& cell = table[hashcode]; 
    auto itr = begin(cell); 
    bool keyExists = false; 
    for(; itr != cell.end() ; itr++){
        if(itr->first == key){ // key exists
            keyExists =  true; 
            itr = cell.erase(itr); // assing return value to iterator to not to cause a segfault
            cout <<  "Item removed" << endl ; 
            break; 
        }
    }
    if(!keyExists){
        cout << "Item not found"<< endl; 
    }
    return ; 

}

void HashTable::printTable(){
    for(int i = 0;i<hashGroups;i++){
        if(table[i].size() == 0) continue;
        auto itr = table[i].begin();
        for(; itr != table[i].end();itr++){
            cout << "Key: " << itr->first << " Value: "<< itr->second << endl ; 
        } 
             
    } 
}

int main(){
    HashTable table ; 
    table.insertItem(502, "ozan");
    table.insertItem(54562, "bob");
    table.insertItem(546, "jack");
    table.insertItem(3489, "john");
    table.insertItem(29, "gokhan");
    table.insertItem(100, "nadia");

    table.printTable(); 
    table.removeItem(29); 
    table.printTable(); 
    
}