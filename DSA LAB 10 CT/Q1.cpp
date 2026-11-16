#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string tag;
    int count;
    Node* next;
};
class HashTable
{
private:
    static const int SIZE = 10;
    Node* table[SIZE];

public:
    // Constructor
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    // Hash Function
    int hashFunction(string tag)
    {
        int sum = 0;

        for (int i = 0; i < tag.length(); i++)
        {
            sum += tag[i];
        }

        return sum % SIZE;
    }

    // Insert Hashtag
    void insert(string tag)
    {
        int index = hashFunction(tag);

        Node* temp = table[index];

        // Check if hashtag already exists
        while (temp != NULL)
        {
            if (temp->tag == tag)
            {
                temp->count++;
                cout << "Count updated!\n";
                checkLongestChain();
                return;
            }

            temp = temp->next;
        }

        // Create new node
        Node* newNode = new Node;

        newNode->tag = tag;
        newNode->count = 1;
        newNode->next = table[index];

        table[index] = newNode;

        cout << "Hashtag inserted!\n";

        checkLongestChain();
    }

    // Search Hashtag
    void search(string tag)
    {
        int index = hashFunction(tag);

        Node* temp = table[index];

        while (temp != NULL)
        {
            if (temp->tag == tag)
            {
                cout << "Usage Count: " << temp->count << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Hashtag not found!\n";
    }

    // Remove Hashtag
    void remove(string tag)
    {
        int index = hashFunction(tag);

        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL)
        {
            if (temp->tag == tag)
            {
                if (prev == NULL)
                {
                    table[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                delete temp;

                cout << "Hashtag removed!\n";

                checkLongestChain();
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Hashtag not found!\n";
    }

    // Find Longest Chain
    void checkLongestChain()
    {
        int longest = 0;

        for (int i = 0; i < SIZE; i++)
        {
            int length = 0;

            Node* temp = table[i];

            while (temp != NULL)
            {
                length++;
                temp = temp->next;
            }

            if (length > longest)
            {
                longest = length;
            }
        }

        cout << "Longest Chain: " << longest << endl;

        if (longest > 5)
        {
            cout << "WARNING: System Overload!\n";
        }
    }

    // Display Hash Table
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";

            Node* temp = table[i];

            while (temp != NULL)
            {
                cout << "[" << temp->tag << ", "
                     << temp->count << "] -> ";

                temp = temp->next;
            }

            cout << "NULL\n";
        }
    }

    // Destructor
    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* temp = table[i];

            while (temp != NULL)
            {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
    }
};
int main()
{
    HashTable h;
    int choice;
    string tag;
    do
    {
        cout << "\n===== SOCIAL MEDIA HASHTAG TRACKER =====\n";
        cout << "1. Insert Hashtag\n";
        cout << "2. Search Hashtag\n";
        cout << "3. Remove Hashtag\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Find Longest Chain\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter Hashtag: ";
                cin >> tag;
                h.insert(tag);
                break;
            case 2:
                cout << "Enter Hashtag to Search: ";
                cin >> tag;
                h.search(tag);
                break;
            case 3:
                cout << "Enter Hashtag to Remove: ";
                cin >> tag;
                h.remove(tag);
                break;
            case 4:
                h.display();
                break;
            case 5:
                h.checkLongestChain();
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

