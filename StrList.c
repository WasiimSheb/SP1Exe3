#include<stdlib.h>
#include<string.h>
#include "StrList.h"
#include <stdio.h>

// Structure for a Node in the StrList
typedef struct Node
{
    char* value;        // Value of the node
    struct Node* _next; // Pointer to the next node
} Node;

// Structure for the StrList
typedef struct _StrList
{
    Node* head;     // Pointer to the head of the list
    size_t size;    // Size of the list
} StrList;

// Allocate memory for a Node and initialize its value
Node* Node_alloc(char* value){
    Node* allocate = (Node*) malloc(sizeof(Node));
    if (allocate == NULL){return NULL;}
    allocate -> value = value;
    return allocate;
}

// Free memory allocated for a Node
void Nodefree(Node* p){
    free(p -> value);
    free(p);
}

// Allocate memory for a StrList
StrList* StrList_alloc() {
    StrList* p = (StrList*)malloc(sizeof(StrList));
    if(p == NULL) {return NULL;}
    p -> head = NULL;
    p -> size = 0;
    return p;
}

// Free memory allocated for a StrList
void StrList_free(StrList* StrList) {
    if (StrList) {
        Node* node = StrList-> head;
        while (node) {
            Node* temp = node;
            node = node->_next;
            free(temp-> value);
            free(temp);
        }
        free(StrList);
    }
}

// Get the size of the StrList
size_t StrList_size(const StrList* StrList){
    return StrList -> size;
}

// Insert a new node at the end of the StrList
void StrList_insertLast(StrList* StrList, const char* data){
    if(StrList == NULL){ return;}
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = strdup(data);
    newNode -> _next = NULL;

    if (StrList -> head == NULL){
        StrList -> head = newNode;
    }
    else{
        Node *temp = StrList -> head;
        while (temp -> _next != NULL){
            temp = temp -> _next;
        }
        temp -> _next = newNode;
    }
    StrList -> size++;
}

// Insert a new node at a specific index in the StrList
void StrList_insertAt(StrList* StrList, const char* data, int index){
    if (index >= StrList_size(StrList) || StrList == NULL || index < 0){
        printf("\n");
        return;
    }
    Node* newNode = (Node*) malloc(sizeof (Node));
    if(newNode == NULL){
        printf("\n");
        return;
    }
    newNode -> value = strdup(data);
    if (newNode -> value == NULL){
        Nodefree(newNode);
        return;
    }
    newNode -> _next = NULL;
    if (index == 0) {
        newNode->_next = StrList->head;
        StrList -> head = newNode;
    } else {
        int n = 0;
        Node* current = StrList -> head;
        while (n < index - 1 && current != NULL){
            current = current -> _next;
            n += 1;
        }
        if(current != NULL){
            newNode -> _next = current -> _next;
            current -> _next = newNode;
        }
    }
    StrList->size++;
}

// Get the value of the first node in the StrList
char* StrList_firstData(const StrList* StrList){
    if (StrList != NULL){
        if (StrList -> head != NULL){
            return StrList -> head -> value;
        }
    }
    return NULL;
}

// Print all elements in the StrList
void StrList_print(const StrList* StrList) {
    if(StrList == NULL || StrList -> head == NULL){
        printf("\n");
        return;
    }
    Node *current = StrList->head;
    while (current -> _next != NULL) {
        printf("%s ", current->value);
        current = current->_next;
    }
    printf("%s\n", current->value);
}

// Print the element at a specific index in the StrList
void StrList_printAt(const StrList* Strlist, int index){
    if (Strlist == NULL || index > StrList_size(Strlist) || index < 0){
        return;
    }
    if (Strlist -> head == NULL){ return;}
    if (Strlist -> head -> value == NULL){ return;}
    Node* temp = Strlist -> head;
    int n = 0;
    while (temp != NULL && n < index){
        temp = temp -> _next;
        n += 1;
    }
    if(temp == NULL || temp -> value == NULL){ return;}
    char *curr = temp -> value;
    printf("%s\n", curr);
}

// Get the total length of all elements in the StrList
int StrList_printLen(const StrList* Strlist){
    if(Strlist == NULL){return 0;}
    int sum = 0;
    Node* temp = Strlist -> head;
    while (temp != NULL){
        if(temp -> value != NULL){
            sum += strlen(temp -> value);
        }
        else {
            sum += 0;
        }
        temp = temp->_next;
    }
    return sum;
}

// Count occurrences of a specific string in the StrList
int StrList_count(StrList* StrList, const char* data){
    if (StrList == NULL || StrList -> head == NULL){return 0;}
    Node* curr = StrList -> head;
    int counter = 0;
    while(curr != NULL){
        if(strcmp(curr -> value, data) == 0){
            counter+= 1;
        }
        curr = curr -> _next;
    }
    return counter;
}

// Remove all occurrences of a specific string from the StrList
void StrList_remove(StrList* StrList, const char* data){
    if (StrList == NULL || StrList -> head == NULL){return;}
    Node* curr = StrList->head;
    Node* prev = NULL;
    Node* temp = NULL;
    while (curr != NULL) {
        if (strcmp(curr->value, data) == 0) {
            if (prev == NULL) {
                StrList->head = curr->_next;
            } else {
                prev->_next = curr->_next;
            }
            temp = curr;
            curr = curr->_next;
            free(temp->value);
            free(temp);
            StrList->size--;
        } else {
            prev = curr;
            curr = curr->_next;
        }
    }
}

// Remove the element at a specific index in the StrList
void StrList_removeAt(StrList* StrList, int index){
    if (StrList == NULL || StrList -> head == NULL || index >= StrList_size(StrList) || index < 0){
        return;
    }
    Node* temp = StrList -> head;
    Node* prev = NULL;
    int n = 0;
    while (temp != NULL && n < index){
        prev = temp;
        temp = temp -> _next;
        n++;
    }
    if(temp == NULL){return;}
    if(prev == NULL){
        StrList -> head = temp -> _next;
    }
    else{
        prev -> _next = temp -> _next;
    }
    free(temp -> value);
    free(temp);
    StrList -> size--;
}

// Check if two StrLists are equal
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if((StrList1 == NULL && StrList2 != NULL) || (StrList1 != NULL && StrList2 == NULL)){return 0;}
    if(StrList_size(StrList1) != StrList_size(StrList2)){return 0;}
    if(StrList1 == NULL && StrList2 == NULL){return 1;}
    if(StrList2 -> head == NULL || StrList1 -> head == NULL){return 0;}
    Node* st1 = StrList1 -> head;
    Node* st2 = StrList2 -> head;
    while (st1 != NULL && st2 != NULL){
        if(strcmp(st1 -> value, st2 -> value) != 0){
            return 0;
        }
        else {
            st1 = st1 -> _next;
            st2 = st2 -> _next;
        }
    }
    return 1;
}

// Clone a StrList
StrList* StrList_clone(const StrList* OriginalList){
    if(OriginalList == NULL || OriginalList -> head == NULL){return NULL;}
    StrList* p = StrList_alloc();
    if( p == NULL ){return NULL;}
    Node* temp1 = OriginalList -> head;
    Node* temp3 = NULL;
    while (temp1 != NULL){
        Node* l = (Node*) malloc(sizeof (Node));
        if(l == NULL){
            StrList_free(p);
            return NULL;
        }
        l -> _next = NULL;
        l -> value = strdup(temp1 -> value);
        if(temp3 == NULL){p -> head = l;}
        else{temp3 -> _next = l;}
        temp3 = l;
        temp1 = temp1 -> _next;
        p -> size++;
    }
    return p;
}

// Reverse the StrList
void StrList_reverse(StrList* StrList){
    if(StrList == NULL || StrList -> head == NULL || StrList -> head -> _next == NULL){ return;}
    if(StrList_size(StrList) == 1){ return;}
    Node *prev = NULL;
    Node *current = StrList -> head;
    Node *next = NULL;

    while (current != NULL) {
        next = current -> _next;
        current -> _next = prev;
        prev = current;
        current = next;
    }
    StrList -> head = prev;
}

// Sort the StrList using the BubbleSort Algorithm
void StrList_sort( StrList* StrList){
    if (StrList == NULL || StrList -> head == NULL || StrList -> head -> _next == NULL) {
        return;
    }
    int swapped;
    do {
        swapped = 0;
        Node *temp = StrList -> head;
        while (temp->_next != NULL) {
            if (strcmp(temp -> value, temp -> _next -> value) > 0) {
                char *c = temp -> value;
                temp -> value = temp -> _next -> value;
                temp -> _next -> value = c;
                swapped = 1;
            }
            temp = temp -> _next;
        }
    }while (swapped);
}

// Check if the StrList is sorted
int StrList_isSorted(StrList* StrList) {
    if (StrList == NULL || StrList->head == NULL) {
        return 1;
    }
    if(StrList_size(StrList) == 1) {return 1;}
    Node* current = StrList->head;
    while (current -> _next != NULL) {
        if (strcmp(current -> value, current -> _next -> value) > 0) {
            return 0;
        }
        current = current -> _next;
    }
    return 1;
}
