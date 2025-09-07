#include <iostream>
using namespace std;

// Node Class Definition
class Node {
public:
    int data;
    Node* next;
    Node(int value) 
    {
        data = value;
        next = NULL;
    }
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() 
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) 
    {
        Node* newNode = new Node(value);
        if (head == NULL) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        
    }

    // Insert at specific position (0-based index)
    void insertAtPosition(int value, int pos) 
    {
        if (pos == 0) 
        {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) 
        {
            if (temp == NULL) 
            {
                cout << "Invalid position!\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
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
        Node* temp = head;
        head = head->next;
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
        Node* temp = head;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete specific node by value
    void deleteNode(int key) 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == key) 
        {
            Node* temp = head;
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
            cout << "Element not found!\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // Search element
    int search(int key) 
    {
        Node* temp = head;
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

    // Display list
    void display() 
    {
        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main Function
int main() {
    SinglyLinkedList list;
    int choice, value, pos, key;

    while (true) 
    {
        cout << "\n=== Singly Linked List Menu ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Node\n";
        cout << "7. Search an Element\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                cout << "Inserted at Beginning\n";
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                cout << "Inserted at End\n";
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position (0-based index): ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                cout << "Inserted at position " << pos;
                break;
            case 4:
                list.deleteFromBeginning();
                cout << "Deleted from Beginning\n";
                break;
            case 5:
                list.deleteFromEnd();
                cout << "Deleted from End\n";
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> key;
                list.deleteNode(key);
                cout << key << "Deleted\n";
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                if (list.search(key))
                    cout << "Element found!\n";
                else
                    cout << "Element not found!\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}