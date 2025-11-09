#include <stdio.h>
#include <stdlib.h>

// Single Circular Linked List (SCLL)
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
////////////////// Create ///////
void create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    { // Same as SLL
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head; // Make the list circular
}
//////// Insert at begin ////////////////
void insertAtBegin(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}
///////////////// Insert at end ///// //////
void insertAtEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}
//// ///////// Insert at any position ////////////////
void insertAtPosition(int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (position == 0)
    {
        insertAtBegin(data);
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head && position != 0)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail)
    {
        tail = newNode;
    }
}
///////////////// Delete at begin //////////////
void deleteAtBegin()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
    free(temp);
    printf("Deleted node from beginning.\n");
}
///////////////// Delete at end //////////////
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
        printf("Deleted node from end.\n");
        return;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
    printf("Deleted node from end.\n");
}
///////////////// Delete at any position //////////////
void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int count = 0;
    struct node *temp = head;
    struct node *prev = tail;
    do
    {
        temp = temp->next;
        count++; // count shows no of nodes in the list
    } while (temp != head);
    if (pos < 0 || pos >= count)
    {
        printf("Invalid position: %d\n", pos);
        return;
    }
    if (pos == 0)
    { // Case 1: Delete at beginning
        deleteAtBegin();
        return;
    }
    temp = head;
    for (int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail)
    { // Case 2: Delete at end
        deleteAtEnd();
        return;
    }
    prev->next = temp->next; // Case 3: Delete in middle
    free(temp);
    printf("Deleted node at position %d.\n", pos);
}
// Another version of insertAtPosition, commented out
/*
void insertAtPosition(int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        tail->next = newNode; // Update tail's next to maintain circularity
        return;
    }
    struct node *current = head;
    int i;
    for (i = 1; i < position - 1 && current->next != head; i++)
    {
        current = current->next;
    }
    if (i != position - 1)
    {
        printf("Invalid position\n");
        free(newNode); // Free the allocated memory
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail)
    {
        tail = newNode; // Update tail if newNode is inserted at the end
    }
}
*/
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
    {
        struct node *temp = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head; // Maintain circularity
        }
        free(temp);
        return;
    }
    struct node *current = head;
    struct node *prev = NULL;
    for (int i = 1; i < position; i++)
    {
        prev = current;
        current = current->next;
        if (current == head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    prev->next = current->next;
    if (current == tail)
    {
        tail = prev;
    }
    free(current);
}
*/
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
//////// Reverse //////////
void reverseList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *prevNode = NULL;
    struct node *current = head;
    struct node *nextNode;
    do
    {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    } while (current != head);
    // Swap head and tail pointers
    tail = head;
    head = prevNode;
}
//////// Display /////////
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
//////////// Main ///
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
            printf("The created single circular linked list: \n");
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