#include <stdio.h>
#include <stdlib.h>

// Double Circular Linked List (DCLL)
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
//// Create //////////////
void create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
    { // First node
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    { // Other nodes
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}
//// Insert at any position ///////////
void insertAtPosition(int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (position == 1)
    {
        if (head == NULL)
        { // List is empty
            head = newNode;
            tail = newNode;
            newNode->next = newNode; // Circular link
            newNode->prev = newNode; // Circular link
        }
        else
        { // Insert before the current head
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode; // Update head
        }
        return;
    }
    struct node *current = head;
    int i;
    for (i = 1; i < position - 1 && current->next != head; i++)
    {
        current = current->next;
    }
    if (i != position - 1 || current->next == head)
    {
        if (position > i + 1)
        { // Invalid position
            printf("Invalid position\n");
            free(newNode);
            return;
        }
    }
    newNode->next = current->next; // Insert after the current node
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    if (current == tail)
    {
        tail = newNode; // Update tail if newNode is the new last node
    }
}
//// Delete at any position ////////////////////////
void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    struct node *current = head;
    if (position == 1)
    {
        if (head == tail)
        { // Only one node in the list
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        { // Update the head and tail pointers to maintain circularity
            tail->next = head->next;
            head->next->prev = tail;
            head = head->next; // Update the head pointer
            free(current); // Free the old head
        }
        return;
    }
    int i;
    for (i = 1; i < position && current->next != head; i++)
    {
        current = current->next;
    }
    if (i != position || current->next == head && position > i)
    {
        printf("Invalid position\n");
        return;
    }
    if (current == tail)
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    else
    { // Deleting a node in the middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
}
//////// Searching //////////
int searchElement(struct node *head, int key)
{
    struct node *current = head;
    int position = 1;
    do
    {
        if (current->data == key)
        {
            return position; // Element found
        }
        current = current->next;
        position++;
    } while (current != head);
    return -1; // Element not found
}
//// Reverse ////////////////////////
void reverseList()
{
    struct node *temp = NULL;
    struct node *current = head;
    if (head == NULL)
    {
        return;
    }
    do
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the previous node (which is now the next)
    } while (current != head);
    if (temp != NULL)
    {
        tail = head;
        head = temp->prev;
    }
}
//// Display ///////
void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d (head)\n", current->data);
}
//////// Main /////////
int main()
{
    while (1)
    {
        int ch;
        printf("\n Menu:");
        printf("\n 1. Create");
        printf("\n 2. Insert at any position");
        printf("\n 3. Delete at any position");
        printf("\n 4. Search a data");
        printf("\n 5. Reverse the list");
        printf("\n 6. Exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int n, i;
            printf("\nEnter the number of nodes: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                int data;
                printf("Enter data for node %d: ", i);
                scanf("%d", &data);
                create(data);
            }
            printf("The created double circular linked list: \n");
            display();
            break;
        case 2:
            int data, position;
            printf("\nEnter data for the new node: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            printf("\nThe linked list after insertion:\n");
            display();
            break;
        case 3:
            int pos;
            printf("\nEnter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            printf("\nThe linked list after deletion:\n");
            display();
            break;
        case 4:
            int key, posi;
            printf("Enter the element to search: ");
            scanf("%d", &key);
            posi = searchElement(head, key);
            if (posi != -1)
                printf("Element %d found at position %d\n", key, posi);
            else
                printf("Element %d not found in the list\n", key);
            break;
        case 5:
            reverseList();
            printf("\nThe linked list after reversing:\n");
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("\n Wrong input!");
        }
    }
    return 0;
}