/*
1. Implement all operations for SLL, DLL, SCLL, DCLL.
*/

#include <stdio.h>
#include <stdlib.h>

// ===== Structures for all types of Linked Lists =====
typedef struct SLLNode {
    int data;
    struct SLLNode *next;
} SLLNode;

typedef struct DLLNode {
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

typedef struct SCLLNode {
    int data;
    struct SCLLNode *next;
} SCLLNode;

typedef struct DCLLNode {
    int data;
    struct DCLLNode *prev;
    struct DCLLNode *next;
} DCLLNode;

// ===== Global pointers for each type of Linked List =====
SLLNode *sllHead = NULL;
DLLNode *dllHead = NULL;
SCLLNode *scllHead = NULL;
DCLLNode *dcllHead = NULL;

// ===== Singly Linked List (SLL) Operations =====
void sllInsertAtBeginning(int value) {
    SLLNode *newNode = (SLLNode*)malloc(sizeof(SLLNode));
    newNode->data = value;
    newNode->next = sllHead;
    sllHead = newNode;
}

void sllInsertAtEnd(int value) {
    SLLNode *newNode = (SLLNode*)malloc(sizeof(SLLNode));
    newNode->data = value;
    newNode->next = NULL;

    if (sllHead == NULL) {
        sllHead = newNode;
        return;
    }

    SLLNode *temp = sllHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void sllInsertAtPosition(int value, int pos) {
    if (pos == 1) {
        sllInsertAtBeginning(value);
        return;
    }

    SLLNode *newNode = (SLLNode*)malloc(sizeof(SLLNode));
    newNode->data = value;

    SLLNode *temp = sllHead;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void sllDeleteFromBeginning() {
    if (sllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    SLLNode *temp = sllHead;
    sllHead = sllHead->next;
    free(temp);
}

void sllDeleteFromEnd() {
    if (sllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (sllHead->next == NULL) {
        free(sllHead);
        sllHead = NULL;
        return;
    }

    SLLNode *temp = sllHead;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void sllDeleteFromPosition(int pos) {
    if (sllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        sllDeleteFromBeginning();
        return;
    }

    SLLNode *temp = sllHead;
    SLLNode *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void sllDisplay() {
    SLLNode *temp = sllHead;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int sllCountNodes() {
    int count = 0;
    SLLNode *temp = sllHead;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void sllSearch(int value) {
    SLLNode *temp = sllHead;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found.\n", value);
}

// ===== Doubly Linked List (DLL) Operations =====
void dllInsertAtBeginning(int value) {
    DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dllHead;

    if (dllHead != NULL) {
        dllHead->prev = newNode;
    }
    dllHead = newNode;
}

void dllInsertAtEnd(int value) {
    DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
    newNode->data = value;
    newNode->next = NULL;

    if (dllHead == NULL) {
        newNode->prev = NULL;
        dllHead = newNode;
        return;
    }

    DLLNode *temp = dllHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void dllInsertAtPosition(int value, int pos) {
    if (pos == 1) {
        dllInsertAtBeginning(value);
        return;
    }

    DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
    newNode->data = value;

    DLLNode *temp = dllHead;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void dllDeleteFromBeginning() {
    if (dllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    DLLNode *temp = dllHead;
    dllHead = dllHead->next;
    if (dllHead != NULL) {
        dllHead->prev = NULL;
    }
    free(temp);
}

void dllDeleteFromEnd() {
    if (dllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (dllHead->next == NULL) {
        free(dllHead);
        dllHead = NULL;
        return;
    }

    DLLNode *temp = dllHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void dllDeleteFromPosition(int pos) {
    if (dllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        dllDeleteFromBeginning();
        return;
    }

    DLLNode *temp = dllHead;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void dllDisplayForward() {
    DLLNode *temp = dllHead;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void dllDisplayBackward() {
    if (dllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    DLLNode *temp = dllHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int dllCountNodes() {
    int count = 0;
    DLLNode *temp = dllHead;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void dllSearch(int value) {
    DLLNode *temp = dllHead;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found.\n", value);
}

// ===== Singly Circular Linked List (SCLL) Operations =====
void scllInsertAtBeginning(int value) {
    SCLLNode *newNode = (SCLLNode*)malloc(sizeof(SCLLNode));
    newNode->data = value;

    if (scllHead == NULL) {
        scllHead = newNode;
        newNode->next = scllHead;
        return;
    }

    SCLLNode *temp = scllHead;
    while (temp->next != scllHead) {
        temp = temp->next;
    }
    newNode->next = scllHead;
    scllHead = newNode;
    temp->next = scllHead;
}

void scllInsertAtEnd(int value) {
    SCLLNode *newNode = (SCLLNode*)malloc(sizeof(SCLLNode));
    newNode->data = value;

    if (scllHead == NULL) {
        scllHead = newNode;
        newNode->next = scllHead;
        return;
    }

    SCLLNode *temp = scllHead;
    while (temp->next != scllHead) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = scllHead;
}

void scllInsertAtPosition(int value, int pos) {
    if (pos == 1) {
        scllInsertAtBeginning(value);
        return;
    }

    SCLLNode *newNode = (SCLLNode*)malloc(sizeof(SCLLNode));
    newNode->data = value;

    SCLLNode *temp = scllHead;
    for (int i = 1; i < pos - 1 && temp->next != scllHead; i++) {
        temp = temp->next;
    }

    if (temp->next == scllHead && pos > 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void scllDeleteFromBeginning() {
    if (scllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (scllHead->next == scllHead) {
        free(scllHead);
        scllHead = NULL;
        return;
    }

    SCLLNode *temp = scllHead;
    while (temp->next != scllHead) {
        temp = temp->next;
    }
    SCLLNode *toDelete = scllHead;
    scllHead = scllHead->next;
    temp->next = scllHead;
    free(toDelete);
}

void scllDeleteFromEnd() {
    if (scllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (scllHead->next == scllHead) {
        free(scllHead);
        scllHead = NULL;
        return;
    }

    SCLLNode *temp = scllHead;
    while (temp->next->next != scllHead) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = scllHead;
}

void scllDeleteFromPosition(int pos) {
    if (scllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        scllDeleteFromBeginning();
        return;
    }

    SCLLNode *temp = scllHead;
    for (int i = 1; i < pos - 1 && temp->next != scllHead; i++) {
        temp = temp->next;
    }

    if (temp->next == scllHead) {
        printf("Invalid position.\n");
        return;
    }

    SCLLNode *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void scllDisplay() {
    if (scllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    SCLLNode *temp = scllHead;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != scllHead);
    printf("HEAD\n");
}

int scllCountNodes() {
    if (scllHead == NULL) {
        return 0;
    }

    int count = 0;
    SCLLNode *temp = scllHead;
    do {
        count++;
        temp = temp->next;
    } while (temp != scllHead);
    return count;
}

void scllSearch(int value) {
    if (scllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    SCLLNode *temp = scllHead;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != scllHead);
    printf("Element %d not found.\n", value);
}

// ===== Doubly Circular Linked List (DCLL) Operations =====
void dcllInsertAtBeginning(int value) {
    DCLLNode *newNode = (DCLLNode*)malloc(sizeof(DCLLNode));
    newNode->data = value;

    if (dcllHead == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        dcllHead = newNode;
        return;
    }

    DCLLNode *last = dcllHead->prev;
    newNode->next = dcllHead;
    newNode->prev = last;
    dcllHead->prev = newNode;
    last->next = newNode;
    dcllHead = newNode;
}

void dcllInsertAtEnd(int value) {
    DCLLNode *newNode = (DCLLNode*)malloc(sizeof(DCLLNode));
    newNode->data = value;

    if (dcllHead == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        dcllHead = newNode;
        return;
    }

    DCLLNode *last = dcllHead->prev;
    newNode->next = dcllHead;
    newNode->prev = last;
    last->next = newNode;
    dcllHead->prev = newNode;
}

void dcllInsertAtPosition(int value, int pos) {
    if (pos == 1) {
        dcllInsertAtBeginning(value);
        return;
    }

    DCLLNode *newNode = (DCLLNode*)malloc(sizeof(DCLLNode));
    newNode->data = value;

    DCLLNode *temp = dcllHead;
    for (int i = 1; i < pos - 1 && temp->next != dcllHead; i++) {
        temp = temp->next;
    }

    if (temp->next == dcllHead && pos > 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void dcllDeleteFromBeginning() {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (dcllHead->next == dcllHead) {
        free(dcllHead);
        dcllHead = NULL;
        return;
    }

    DCLLNode *last = dcllHead->prev;
    DCLLNode *toDelete = dcllHead;
    dcllHead = dcllHead->next;
    dcllHead->prev = last;
    last->next = dcllHead;
    free(toDelete);
}

void dcllDeleteFromEnd() {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (dcllHead->next == dcllHead) {
        free(dcllHead);
        dcllHead = NULL;
        return;
    }

    DCLLNode *last = dcllHead->prev;
    last->prev->next = dcllHead;
    dcllHead->prev = last->prev;
    free(last);
}

void dcllDeleteFromPosition(int pos) {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        dcllDeleteFromBeginning();
        return;
    }

    DCLLNode *temp = dcllHead;
    for (int i = 1; i < pos && temp->next != dcllHead; i++) {
        temp = temp->next;
    }

    if (temp->next == dcllHead && pos > 1) {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void dcllDisplayForward() {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    DCLLNode *temp = dcllHead;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != dcllHead);
    printf("HEAD\n");
}

void dcllDisplayBackward() {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    DCLLNode *temp = dcllHead->prev;
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != dcllHead->prev);
    printf("HEAD\n");
}

int dcllCountNodes() {
    if (dcllHead == NULL) {
        return 0;
    }

    int count = 0;
    DCLLNode *temp = dcllHead;
    do {
        count++;
        temp = temp->next;
    } while (temp != dcllHead);
    return count;
}

void dcllSearch(int value) {
    if (dcllHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    DCLLNode *temp = dcllHead;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != dcllHead);
    printf("Element %d not found.\n", value);
}

// ===== Main Menu =====
void displayMenu() {
    printf("\n===== Linked List Operations =====\n");
    printf("1. Singly Linked List (SLL)\n");
    printf("2. Doubly Linked List (DLL)\n");
    printf("3. Singly Circular Linked List (SCLL)\n");
    printf("4. Doubly Circular Linked List (DCLL)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void sllMenu() {
    int choice, value, pos;
    while (1) {
        printf("\n===== Singly Linked List (SLL) Operations =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Count nodes\n");
        printf("9. Search element\n");
        printf("10. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                sllInsertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                sllInsertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                sllInsertAtPosition(value, pos);
                break;
            case 4:
                sllDeleteFromBeginning();
                break;
            case 5:
                sllDeleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                sllDeleteFromPosition(pos);
                break;
            case 7:
                sllDisplay();
                break;
            case 8:
                printf("Total nodes: %d\n", sllCountNodes());
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                sllSearch(value);
                break;
            case 10:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void dllMenu() {
    int choice, value, pos;
    while (1) {
        printf("\n===== Doubly Linked List (DLL) Operations =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display forward\n");
        printf("8. Display backward\n");
        printf("9. Count nodes\n");
        printf("10. Search element\n");
        printf("11. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                dllInsertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                dllInsertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                dllInsertAtPosition(value, pos);
                break;
            case 4:
                dllDeleteFromBeginning();
                break;
            case 5:
                dllDeleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                dllDeleteFromPosition(pos);
                break;
            case 7:
                dllDisplayForward();
                break;
            case 8:
                dllDisplayBackward();
                break;
            case 9:
                printf("Total nodes: %d\n", dllCountNodes());
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &value);
                dllSearch(value);
                break;
            case 11:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void scllMenu() {
    int choice, value, pos;
    while (1) {
        printf("\n===== Singly Circular Linked List (SCLL) Operations =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Count nodes\n");
        printf("9. Search element\n");
        printf("10. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                scllInsertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                scllInsertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                scllInsertAtPosition(value, pos);
                break;
            case 4:
                scllDeleteFromBeginning();
                break;
            case 5:
                scllDeleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                scllDeleteFromPosition(pos);
                break;
            case 7:
                scllDisplay();
                break;
            case 8:
                printf("Total nodes: %d\n", scllCountNodes());
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                scllSearch(value);
                break;
            case 10:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void dcllMenu() {
    int choice, value, pos;
    while (1) {
        printf("\n===== Doubly Circular Linked List (DCLL) Operations =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display forward\n");
        printf("8. Display backward\n");
        printf("9. Count nodes\n");
        printf("10. Search element\n");
        printf("11. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                dcllInsertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                dcllInsertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                dcllInsertAtPosition(value, pos);
                break;
            case 4:
                dcllDeleteFromBeginning();
                break;
            case 5:
                dcllDeleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                dcllDeleteFromPosition(pos);
                break;
            case 7:
                dcllDisplayForward();
                break;
            case 8:
                dcllDisplayBackward();
                break;
            case 9:
                printf("Total nodes: %d\n", dcllCountNodes());
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &value);
                dcllSearch(value);
                break;
            case 11:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sllMenu();
                break;
            case 2:
                dllMenu();
                break;
            case 3:
                scllMenu();
                break;
            case 4:
                dcllMenu();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}