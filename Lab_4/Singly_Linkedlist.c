#include <stdio.h>
#include <stdlib.h>

// Node Definition
struct Node 
{
    int data;
    struct Node* next;
};

// Function Prototypes
struct Node* createNode(int value);
struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAtPosition(struct Node* head, int value, int pos);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteNode(struct Node* head, int key);
int search(struct Node* head, int key);
void display(struct Node* head);



// Main 
int main() 
{
    struct Node* head = NULL;
    int choice, value, pos, key;

    while (true) 
    {
        printf("\n=== Singly Linked List Menu ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Node\n");
        printf("7. Search an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                printf("Inserted at Beginning\n");
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printf("Inserted at End\n");
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                printf("Inserted at %d position\n",pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                printf("Deleted from Beginning\n");
                break;
            case 5:
                head = deleteFromEnd(head);
                printf("Deleted from End\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                printf("%d Deleted",key);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
// Function Defination

// Create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) 
{
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int value) 
{
    struct Node* newNode = createNode(value);
    if (head == NULL) 
    {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at specific position
struct Node* insertAtPosition(struct Node* head, int value, int pos) 
{
    if (pos == 0) 
    {
        return insertAtBeginning(head, value);
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) 
    {
        if (temp == NULL) 
        {
            printf("Invalid position!\n");
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete specific node by value
struct Node* deleteNode(struct Node* head, int key) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (head->data == key) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) 
    {
        temp = temp->next;
    }
    if (temp->next == NULL) 
    {
        printf("Element not found!\n");
        return head;
    }
    struct Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

// Search an element
int search(struct Node* head, int key) 
{
    struct Node* temp = head;
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
void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}