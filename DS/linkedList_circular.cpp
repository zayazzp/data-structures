#include <iostream>
using namespace std;
// Circular Linked List
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int num)
    {
        data = num;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *last;
    LinkedList()
    {
        last = NULL;
    }

    void addInLast(Node *n);
    void display();
    void addInFront(Node *n);
    bool remove(int num);
};
void printMenu();
int main()
{
    LinkedList l1;
    Node *n1;
    int choice, number;
    bool loop = true;
    while (loop)
    {
        printMenu();
        cout << "Enter your number: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Insert
            while (1)
            {
                cout << "Enter a number (0 to end): ";
                cin >> number;
                if (number == 0)
                {
                    break;
                }
                n1 = new Node(number);
                l1.addInLast(n1);
            }
            break;
        case 2:
            // Display
            l1.display();
            break;
        case 3:
            // Enter in front
            cout << "Enter a number to place in front" << endl;
            cin >> number;
            n1 = new Node(number);
            l1.addInFront(n1);
            break;
        case 4:
            // Delete
            cout << "Delete" << endl;
            cin >> number;
            if (l1.remove(number))
            {
                cout << "Number deleted" << endl;
            }
            else
            {
                cout << "Number not deleted" << endl;
            }
            break;
        case 0:
            // Exiting
            loop = false;
            break;
        default:
            cout << choice << "Invalid entry" << endl;
        }
    }
}

void printMenu()
{
    cout << "******Menu******" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Display" << endl;
    cout << "3. Insert in the front" << endl;
    cout << "4. Delete an item from the linked list" << endl;
    cout << "0. Exit" << endl;
}

void LinkedList::addInLast(Node *n)
{
    if (last == NULL)
    {
        last = n;
        n->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

void LinkedList::display()
{
    Node *ptr = last;
    if (last == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        ptr = ptr->next;
        while (ptr != last)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << " ";
        cout << endl;
    }
}

void LinkedList::addInFront(Node *n)
{
    Node *ptr = last;
    if (last == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}
bool LinkedList::remove(int num)
{
    Node *current = last;
    // If the linkedlist is empty
    if (last == NULL)
    {
        return false;
    }
    // If removing number is the only number
    else if (current->next == last && current->data == num)
    {
        current->next = NULL;
        last = NULL;
        return true;
    }
    else
    {
        // checking all number except last
        while (current->next != last)
        {
            if (current->next->data == num)
            {
                Node *tmp = current->next;
                current->next = tmp->next;
                return true;
            }
            current = current->next;
        }
        // checking the last number
        if (current->next->data == num)
        {
            last = current;
            current->next = current->next->next;
            return true;
        }
    }
    return false;
}