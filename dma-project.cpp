#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class DMA
{
public:
    Node* head;
    DMA()
    {
        head = NULL;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "List is empty";
            return;
        }
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void addAtBeg(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int key)
    {
        Node* temp = head;
        int count = 0;

        while(temp != NULL)
        {
            if(temp->data == key)
            {
                cout << "Found at position: " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Value not found\n";
    }

    void deleteNode(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key)
        {
            Node* temp = head;
            cout << "Deleted: " << temp->data << endl;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != key)
        {
            temp = temp->next;
        }
        
        if (temp->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node* delNode = temp->next;
        cout << "Deleted: " << delNode->data << endl;

        temp->next = delNode->next;
        delete delNode;
    }

    void reverse()
    {
        if(head == NULL)
        {
            cout << "List is empty";
            return;
        }
        Node * previous = NULL;
        Node* current = head;
        Node* next = NULL;

        while(current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
};

int main()
{
    DMA d;
    int choice, value;

    do
    {
        cout << "\n---- MENU ----" << endl;
        cout << "1. Append (insert at end)" << endl;
        cout << "2. Display" << endl;
        cout << "3. Insert at Beginning" << endl;
        cout << "4. Search" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Reverse" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            d.appEnd(value);
            break;

        case 2:
            d.display();
            break;

        case 3:
            cout << "Enter Value: ";
            cin >> value;
            d.addAtBeg(value);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            d.search(value);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            d.deleteNode(value);
            break;

        case 6:
            d.reverse();
            cout << "List Reversed" << endl;
            break;

        case 7:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (choice != 7);
}
