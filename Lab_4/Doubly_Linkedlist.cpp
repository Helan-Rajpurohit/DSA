#include <iostream>
using namespace std;

// Node Class Definition
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int value) 
    {
        data = value;
        prev = ;
        next = NULL;
    }
};

//Doubly Linked List Class
class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() 
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) 
    {
        DNode* newNode = new DNode(value);
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) 
    {
        DNode* newNode = new DNode(value);
        if (head == NULL) 
        {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at position (0-based index)
    void insertAtPosition(int value, int pos) 
    {
        if (pos == 0) 
        {
            insertAtBeginning(value);
            return;
        }
        DNode* newNode = new DNode(value);
        DNode* temp = head;
        for (int i = 0; i < pos - 1; i++) 
        {
            if (temp == nullptr) 
            {
                cout << "Invalid position!\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) 
        {
            delete head;
            head = NULL;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    // Delete at position
    void deleteAtPosition(int pos) 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        if (pos == 0) 
        {
            deleteFromBeginning();
            return;
        }
        DNode* temp = head;
        for (i = 0; i < pos; i++) 
        {
            if (temp == NULL) 
            {
                cout << "Invalid position!\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) 
        {
            cout << "Invalid position!\n";
            return;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Search for element
    int search(int key) 
    {
        DNode* temp = head;
        while (temp != NULL) 
        {
            if (temp->data == key)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }

    // Display forward
    void displayForward() 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        cout << "Forward: ";
        DNode* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display backward
    void displayBackward() 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        cout << "Backward: ";
        while (temp != NULL) 
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

// Main Function
int main() 
{
    DoublyLinkedList dll;
    int choice, value, pos, key;

    while (true) 
    {
        cout << "\n=== Doubly Linked List Menu ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search an Element\n";
        cout << "8. Display Forward\n";
        cout << "9. Display Backward\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtBeginning(value);
                cout << "Inserted at Beginning";
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                cout << "Inserted at End";
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position (0-based index): ";
                cin >> pos;
                dll.insertAtPosition(value, pos);
                break;
            case 4:
                dll.deleteFromBeginning();
                break;
            case 5:
                dll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position (0-based index): ";
                cin >> pos;
                dll.deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                if (dll.search(key))
                    cout << "Element found!\n";
                else
                    cout << "Element not found!\n";
                break;
            case 8:
                dll.displayForward();
                break;
            case 9:
                dll.displayBackward();
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}