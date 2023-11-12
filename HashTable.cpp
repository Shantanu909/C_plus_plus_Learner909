#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class HashTable {
private:
    vector<list<int>> table; 
    int tableSize;

  
    int hash(int key) {
        return key % tableSize;
    }

public:
    HashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }

  
    void insertSeparateChaining(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }


    bool searchSeparateChaining(int key) {
        int index = hash(key);
        for (int k : table[index]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }

   
    void removeSeparateChaining(int key) {
        int index = hash(key);
        table[index].remove(key);
    }


    void insertLinearProbing(int key) {
        int index = hash(key);

        while (!table[index].empty()) {
            index = (index + 1) % tableSize; 
        }

        table[index].push_back(key);
    }


    bool searchLinearProbing(int key) {
        int index = hash(key);

        while (!table[index].empty()) {
            if (table[index].front() == key) {
                return true;
            }
            index = (index + 1) % tableSize; 
        }

        return false;
    }


    void removeLinearProbing(int key) {
        int index = hash(key);

        while (!table[index].empty()) {
            if (table[index].front() == key) {
                table[index].clear();
                return;
            }
            index = (index + 1) % tableSize;
        }
    }


    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "null" << endl;
        }
    }
};

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;
    HashTable hashTable(tableSize);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert (Separate Chaining)\n";
        cout << "2. Search (Separate Chaining)\n";
        cout << "3. Remove (Separate Chaining)\n";
        cout << "4. Insert (Linear Probing)\n";
        cout << "5. Search (Linear Probing)\n";
        cout << "6. Remove (Linear Probing)\n";
        cout << "7. Display Hash Table\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        int key;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insertSeparateChaining(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (hashTable.searchSeparateChaining(key)) {
                    cout << "Key found in the hash table." << endl;
                } else {
                    cout << "Key not found in the hash table." << endl;
                }
                break;
            case 3:
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.removeSeparateChaining(key);
                break;
            case 4:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insertLinearProbing(key);
                break;
            case 5:
                cout << "Enter key to search: ";
                cin >> key;
                if (hashTable.searchLinearProbing(key)) {
                    cout << "Key found in the hash table." << endl;
                } else {
                    cout << "Key not found in the hash table." << endl;
                }
                break;
            case 6:
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.removeLinearProbing(key);
                break;
            case 7:
                cout << "Hash Table (Separate Chaining):\n";
                hashTable.display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
