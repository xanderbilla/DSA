#include <iostream>

class HashTable {
private:
    static const int tableSize = 10;
    int table[tableSize];

    int hashFunction1(int key) {
        return key % tableSize;
    }

    int hashFunction2(int key) {
        // Choose a step size that is relatively prime to the table size
        return 7 - (key % 7);
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = -1; // -1 indicates an empty slot
        }
    }

    void insert(int key) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int i = 0;

        // Double hashing to find the next available slot
        while (table[index] != -1) {
            index = (index + i * stepSize) % tableSize;
            ++i;
        }

        // Insert the key into the found slot
        table[index] = key;
    }

    void remove(int key) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int i = 0;

        // Double hashing to find the key or an empty slot
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1; // Mark the slot as empty
                return;
            }

            index = (index + i * stepSize) % tableSize;
            ++i;
        }

        // Key not found
        std::cout << "Key " << key << " not found in the hash table." << std::endl;
    }

    bool search(int key) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int i = 0;

        // Double hashing to find the key or an empty slot
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }

            index = (index + i * stepSize) % tableSize;
            ++i;
        }

        // Key not found
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "[" << i << "]: " << table[i] << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert some values into the hash table
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(6);
    hashTable.insert(16);

    // Display the hash table
    std::cout << "Hash Table:" << std::endl;
    hashTable.display();

    // Search for a key
    int keyToSearch = 15;
    if (hashTable.search(keyToSearch)) {
        std::cout << "Key " << keyToSearch << " found in the hash table." << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found in the hash table." << std::endl;
    }

    // Remove a key
    int keyToRemove = 6;
    hashTable.remove(keyToRemove);

    // Display the updated hash table
    std::cout << "\nUpdated Hash Table:" << std::endl;
    hashTable.display();

    return 0;
}
