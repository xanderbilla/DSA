#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class HashTable {
private:
    static const int tableSize = 10;
    Node* table[tableSize];

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return; // Key not found
        }

        if (prev == nullptr) {
            table[index] = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "[" << i << "]: ";
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
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
