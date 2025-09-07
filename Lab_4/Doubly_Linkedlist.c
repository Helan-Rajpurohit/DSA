#include <stdio.h>
#include <stdlib.h>

// Node Definition
struct DNode 
{
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function Prototypes
struct DNode* createDNode(int value);
struct DNode* insertAtBeginning_DLL(struct DNode* head, int value);
struct DNode* insertAtEnd_DLL(struct DNode* head, int value);
struct DNode* insertAtPosition_DLL(struct DNode* head, int value, int pos);
struct DNode* deleteFromBeginning_DLL(struct DNode* head);
struct DNode* deleteFromEnd_DLL(struct DNode* head);
struct DNode* deleteAtPosition_DLL(struct DNode* head, int pos);
bool search_DLL(struct DNode* head, int key);
void displayForward_DLL(struct DNode* head);
void displayBackward_DLL(struct DNode* head);



//Main Function
int main() 
{
    struct DNode* head = NULL;
    int choice, value, pos, key;

    while (1) 
    {
        printf("\n=== Doubly Linked List Menu ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Search an Element\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtBeginning_DLL(head, value);
                printf("Inserted at Beginning\n");
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtEnd_DLL(head, value);
                printf("Inserted at End\n");
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                head = insertAtPosition_DLL(head, value, pos);
                printf("Inserted at %d position ",pos);
                break;
            case 4:
                head = deleteFromBeginning_DLL(head);
                printf("Deleted from Beginning\n");
                break;
            case 5:
                head = deleteFromEnd_DLL(head);
                printf("Deleted from End\n");
                break;
            case 6:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                head = deleteAtPosition_DLL(head, pos);
                printf("Deleted from %d position\n",pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search_DLL(head, key))
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;
            case 8:
                displayForward_DLL(head);
                break;
            case 9:
                displayBackward_DLL(head);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
//Function Defination

// Create a new doubly linked list node
struct DNode* createDNode(int value) 
{
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct DNode* insertAtBeginning_DLL(struct DNode* head, int value) 
{
    struct DNode* newNode = createDNode(value);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

// Insert at end
struct DNode* insertAtEnd_DLL(struct DNode* head, int value) 
{
    struct DNode* newNode = createDNode(value);
    if (head == NULL) 
    {
        return newNode;
    }
    struct DNode* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at specific position (0-based index)
struct DNode* insertAtPosition_DLL(struct DNode* head, int value, int pos) 
{
    if (pos == 0) 
    {
        return insertAtBeginning_DLL(head, value);
    }
    struct DNode* newNode = createDNode(value);
    struct DNode* temp = head;
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
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct DNode* deleteFromBeginning_DLL(struct DNode* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return NULL;
    }
    struct DNode* temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Delete from end
struct DNode* deleteFromEnd_DLL(struct DNode* head) 
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
    struct DNode* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Delete at specific position
struct DNode* deleteAtPosition_DLL(struct DNode* head, int pos) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return NULL;
    }
    if (pos == 0) 
    {
        return deleteFromBeginning_DLL(head);
    }
    struct DNode* temp = head;
    for (int i = 0; i < pos; i++) 
    {
        if (temp == NULL) 
        {
            printf("Invalid position!\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        printf("Invalid position!\n");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

// Search for an element
bool search_DLL(struct DNode* head, int key) 
{
    struct DNode* temp = head;
    while (temp != NULL) 
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Display list forward
void displayForward_DLL(struct DNode* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    printf("Forward: ");
    struct DNode* temp = head;
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display list backward
void displayBackward_DLL(struct DNode* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct DNode* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

