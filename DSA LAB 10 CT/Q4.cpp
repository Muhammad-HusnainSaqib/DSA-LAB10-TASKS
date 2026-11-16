#include <iostream>
using namespace std;
class HashTable
{
private:
    static const int SIZE = 11;
    static const int PRIME = 7;

    int table[SIZE];

public:

    // Constructor
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }

    // First Hash Function
    int hash1(int key)
    {
        return key % SIZE;
    }

    // Second Hash Function
    int hash2(int key)
    {
        return PRIME - (key % PRIME);
    }

    // Insert Vault Code
    void insert(int key)
    {
        int index = hash1(key);
        int step = hash2(key);

        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * step) % SIZE;

            if (table[current] == -1)
            {
                table[current] = key;

                cout << "Vault code inserted at index "
                     << current << endl;

                return;
            }

            if (table[current] == key)
            {
                cout << "Vault code already exists!\n";
                return;
            }
        }

        cout << "Vault Full! No available slot found.\n";
    }

    // Search Vault Code
    void search(int key)
    {
        int index = hash1(key);
        int step = hash2(key);

        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * step) % SIZE;

            if (table[current] == -1)
            {
                cout << "Vault code not found!\n";
                return;
            }

            if (table[current] == key)
            {
                cout << "Vault code found at index "
                     << current << endl;

                return;
            }
        }

        cout << "Vault code not found!\n";
    }

    // Remove Vault Code
    void remove(int key)
    {
        int index = hash1(key);
        int step = hash2(key);

        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * step) % SIZE;

            if (table[current] == -1)
            {
                cout << "Vault code not found!\n";
                return;
            }

            if (table[current] == key)
            {
                table[current] = -1;

                cout << "Vault code removed!\n";
                return;
            }
        }

        cout << "Vault code not found!\n";
    }

    // Display Hash Table
    void display()
    {
        cout << "\nVault Hash Table:\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";

            if (table[i] == -1)
            {
                cout << "EMPTY";
            }
            else
            {
                cout << table[i];
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    int choice;
    int key;

    do
    {
        cout << "\n===== HIGH SECURITY BANK VAULT =====\n";

        cout << "1. Insert Vault Code\n";
        cout << "2. Search Vault Code\n";
        cout << "3. Remove Vault Code\n";
        cout << "4. Display Vault Table\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Vault Code: ";
                cin >> key;
                h.insert(key);
                break;

            case 2:
                cout << "Enter Vault Code to Search: ";
                cin >> key;
                h.search(key);
                break;

            case 3:
                cout << "Enter Vault Code to Remove: ";
                cin >> key;
                h.remove(key);
                break;

            case 4:
                h.display();
                break;

            case 0:
                cout << "Program Ended!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}

