#include <iostream>
using namespace std;
class HashTable
{
private:
    static const int SIZE = 11;  // Prime number
    int table[SIZE];
    int occupied;
public:
    // Constructor
    HashTable()
    {
        occupied = 0;
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }
    // Hash Function
    int hashFunction(int id)
    {
        return id % SIZE;
    }
    // Calculate Load Factor
    float loadFactor()
    {
        return (float)occupied / SIZE;
    }

    // Insert Booking
    void insert(int id)
    {
        // Check Load Factor
        if (loadFactor() > 0.5)
        {
            cout << "Rehash Needed! New bookings are stopped.\n";
            return;
        }

        int index = hashFunction(id);

        // Quadratic Probing
        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * j) % SIZE;

            if (table[current] == -1)
            {
                table[current] = id;
                occupied++;

                cout << "Booking inserted at seat "
                     << current << endl;

                cout << "Current Load Factor: "
                     << loadFactor() << endl;

                return;
            }

            if (table[current] == id)
            {
                cout << "Booking already exists!\n";
                return;
            }
        }

        cout << "No available seat found!\n";
        cout << "Rehash Needed!\n";
    }

    // Search Booking
    void search(int id)
    {
        int index = hashFunction(id);

        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * j) % SIZE;

            if (table[current] == -1)
            {
                cout << "Booking not found!\n";
                return;
            }

            if (table[current] == id)
            {
                cout << "Booking found at seat "
                     << current << endl;
                return;
            }
        }

        cout << "Booking not found!\n";
    }

    // Delete Booking
    void remove(int id)
    {
        int index = hashFunction(id);

        for (int j = 0; j < SIZE; j++)
        {
            int current = (index + j * j) % SIZE;

            if (table[current] == -1)
            {
                cout << "Booking not found!\n";
                return;
            }

            if (table[current] == id)
            {
                table[current] = -1;
                occupied--;

                cout << "Booking cancelled!\n";

                cout << "Current Load Factor: "
                     << loadFactor() << endl;

                return;
            }
        }

        cout << "Booking not found!\n";
    }

    // Display Hash Table
    void display()
    {
        cout << "\nTheater Booking Table:\n";

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

        cout << "\nLoad Factor: " << loadFactor() << endl;
    }
};
int main()
{
    HashTable h;
    int choice;
    int id;

    do
    {
        cout << "\n===== THEATER BOOKING SYSTEM =====\n";
        cout << "1. Insert Booking\n";
        cout << "2. Search Booking\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Display Bookings\n";
        cout << "5. Show Load Factor\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter Booking ID: ";
                cin >> id;
                h.insert(id);
                break;
            case 2:
                cout << "Enter Booking ID to Search: ";
                cin >> id;
                h.search(id);
                break;
            case 3:
                cout << "Enter Booking ID to Cancel: ";
                cin >> id;
                h.remove(id);
                break;
            case 4:
                h.display();
                break;
            case 5:
                cout << "Current Load Factor: "
                     << h.loadFactor() << endl;
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

