
#include <iostream>
using namespace std;

class HashTable
{
private:
    static const int SIZE = 10;

    int table[SIZE];
    int status[SIZE];
    // 0 = Empty
    // 1 = Occupied
    // 2 = Deleted

public:

    // Constructor
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
            status[i] = 0;
        }
    }

    // Hash Function
    int hashFunction(int id)
    {
        return id % SIZE;
    }

    // Insert Package
    void insert(int id)
    {
        int index = hashFunction(id);
        int probes = 0;

        for (int i = 0; i < SIZE; i++)
        {
            int current = (index + i) % SIZE;

            probes++;

            if (status[current] == 1 && table[current] == id)
            {
                cout << "Package already exists!\n";
                cout << "Total Probes: " << probes << endl;
                return;
            }

            if (status[current] == 0 || status[current] == 2)
            {
                table[current] = id;
                status[current] = 1;

                cout << "Package inserted at locker "
                     << current << endl;

                cout << "Total Probes: " << probes << endl;
                return;
            }
        }

        cout << "Warehouse is full!\n";
        cout << "Total Probes: " << probes << endl;
    }

    // Search Package
    void search(int id)
    {
        int index = hashFunction(id);

        for (int i = 0; i < SIZE; i++)
        {
            int current = (index + i) % SIZE;

            if (status[current] == 0)
            {
                cout << "Package not found!\n";
                return;
            }

            if (status[current] == 1 && table[current] == id)
            {
                cout << "Package found at locker "
                     << current << endl;
                return;
            }

            // If deleted, continue searching
        }

        cout << "Package not found!\n";
    }

    // Delete Package (Lazy Deletion)
    void remove(int id)
    {
        int index = hashFunction(id);

        for (int i = 0; i < SIZE; i++)
        {
            int current = (index + i) % SIZE;

            if (status[current] == 0)
            {
                cout << "Package not found!\n";
                return;
            }

            if (status[current] == 1 && table[current] == id)
            {
                status[current] = 2;

                cout << "Package picked up and locker marked deleted!\n";
                return;
            }
        }

        cout << "Package not found!\n";
    }

    // Display Hash Table
    void display()
    {
        cout << "\nLocker Status:\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";

            if (status[i] == 0)
            {
                cout << "EMPTY";
            }
            else if (status[i] == 1)
            {
                cout << table[i];
            }
            else
            {
                cout << "DELETED";
            }

            cout << endl;
        }
    }
};
int main()
{
    HashTable h;
    int choice;
    int id;
    do
    {
        cout << "\n===== WAREHOUSE LOCKER SYSTEM =====\n";
        cout << "1. Insert Package\n";
        cout << "2. Search Package\n";
        cout << "3. Remove Package\n";
        cout << "4. Display Lockers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter Package ID: ";
                cin >> id;
                h.insert(id);
                break;
            case 2:
                cout << "Enter Package ID to Search: ";
                cin >> id;
                h.search(id);
                break;
            case 3:
                cout << "Enter Package ID to Remove: ";
                cin >> id;
                h.remove(id);
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

