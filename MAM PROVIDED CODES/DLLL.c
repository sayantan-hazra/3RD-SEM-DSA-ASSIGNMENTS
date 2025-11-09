#include <stdio.h>
#include <stdlib.h>

// Double Linear Linked List (DLLL)
////////////////// Declaration of DLLL //////////////
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
/////// Initialization of two Pointers //////
struct node *head = NULL;
struct node *tail = NULL;
//////// Create //////////
void create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    { // Creating first node
        head = newNode;
        tail = newNode;
    }
    else
    { // Creating other nodes
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
//////// Insert at begin //////////
void insertAtBegin(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode; // First node in the list
    head = newNode;
}
//////// Insert at end //////////
void insertAtEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode; // First node in the list
    tail = newNode;
}
//////// Insert at any position //////////
void insertAtPosition(int data, int position)
{
    if (position <= 0 || head == NULL || head->next == NULL)
    {
        printf("Cannot insert at head/tail or list is too short\n");
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Cannot insert at tail or position out of bounds\n");
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
// Another version of insertAtPosition, commented out
/*
void insertAtPosition(int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (position == 1) // Insertion at head position
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct node *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next; // Traverse to the position
    }
    if (current == NULL)
    {
        printf("Invalid position\n");
        free(newNode); // Free the allocated memory
        return;
    }
    newNode->prev = current;
    newNode->next = current->next; // Insertion at position including the last
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
*/
//////// Delete at begin //////////
void deleteAtBegin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // List became empty
    free(temp);
}
//////// Delete at end //////////
void deleteAtEnd()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL; // List became empty
    free(temp);
}
//////// Delete at any position //////////
void deleteAtPosition(int position)
{
    if (head == NULL || position < 0)
    {
        printf("Invalid position or empty list\n");
        return;
    }
    if (position == 0)
    {
        deleteAtBegin();
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    if (temp == tail)
    {
        deleteAtEnd();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
// Another version of deleteAtPosition, commented out
/*
void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    if (position == 1)
    { // Delete from head
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
            free(temp);
            return;
        }
    }
    struct node *current = head;
    for (int i = 1; i < position && current != NULL; i++)
    {
        current = current->next; // Traverse to the position
    }
    if (current == NULL)
    {
        printf("Invalid position\n");
        return;
    } // Delete from position including the last
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
}
*/
//////// Searching //////////
int searchElement(struct node *head, int key)
{
    struct node *current = head;
    int position = 1;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return position; // Element found
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}
//////// Reverse //////////
void reverseList()
{
    struct node *temp = NULL;
    struct node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the previous node
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
}
//////// Display //////////
void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//////////// Main /////////////////
int main()
{
    while (1)
    {
        int ch;
        int data;
        printf("\n Menu:");
        printf("\n 1. Create");
        printf("\n 2. Insert at begin");
        printf("\n 3. Insert at any end");
        printf("\n 4. Insert at any position");
        printf("\n 5. Delete at begin");
        printf("\n 6. Delete at end");
        printf("\n 7. Delete at any position");
        printf("\n 8. Search a data");
        printf("\n 9. Reverse the list");
        printf("\n 10. Exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int n, i;
            printf("\nEnter the number of nodes: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                int data;
                printf("Enter data for node %d: ", i);
                scanf("%d", &data);
                create(data);
            }
            printf("The created double linked list: \n");
            display();
            break;
        case 2:
            printf("\nEnter data for the head node: ");
            scanf("%d", &data);
            insertAtBegin(data);
            printf("\nThe linked list after insertion:\n");
            display();
            break;
        case 3:
            printf("\nEnter data for the tail node: ");
            scanf("%d", &data);
            insertAtEnd(data);
            printf("\nThe linked list after insertion:\n");
            display();
            break;
        case 4:
            int position;
            printf("\nEnter data for the new node: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            printf("\nThe linked list after insertion:\n");
            display();
            break;
        case 5:
            deleteAtBegin();
            printf("\nThe linked list after deletion:\n");
            display();
            break;
        case 6:
            deleteAtEnd();
            printf("\nThe linked list after deletion:\n");
            display();
            break;
        case 7:
            int pos;
            printf("\nEnter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            printf("\nThe linked list after deletion:\n");
            display();
            break;
        case 8:
            int key, posi;
            printf("Enter the element to search: ");
            scanf("%d", &key);
            posi = searchElement(head, key);
            if (posi != -1)
                printf("Element %d found at position %d\n", key, posi);
            else
                printf("Element %d not found in the list\n", key);
            break;
        case 9:
            reverseList();
            printf("\nThe linked list after reversing:\n");
            display();
            break;
        case 10:
            exit(0);
        default:
            printf("\n Wrong input!");
        }
    }
    return 0;
}