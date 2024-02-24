#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for a node in the linked list
typedef struct _node {
    char* _data;
    struct _node* _next;
} Node;

// Define the structure for the StrList
typedef struct _StrList {
    Node* _head;
    size_t _size;
} StrList;

// Node implementation:

Node* Node_alloc(char* str, Node* next) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->_data = str;
    p->_next = next;
    return p;
}

void Node_free(Node* node) {
    if(node->_data != NULL){
        free(node->_data);
    }
    free(node);
}

// List implementation
StrList* StrList_alloc(){
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if (list) {
        list->_head = NULL;
        list->_size = 0;
    }
    return list;
}
void StrList_free(StrList* StrList) {
    if (StrList) {
        Node* node = StrList->_head;
        while (node) {
            Node* temp = node;
            node = node->_next;
            free(temp->_data);
            free(temp);
        }
        free(StrList);
    }
}


size_t StrList_size(const StrList* StrList){
   	return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data) {
    Node* node = Node_alloc(data, NULL);
    if (StrList->_size == 0) {
        StrList->_head = node; // Update head
    } else {
        Node* curr = StrList->_head;
        while (curr->_next != NULL) {
            curr = curr->_next;
        }
        curr->_next = node;
    }
    StrList->_size++;
}
void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if (index < 0 || index > StrList->_size) {
        printf("invalid index\n");
        return;
    }

    Node* node = Node_alloc(data, NULL);
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (index == 0) {
        node->_next = StrList->_head;
        StrList->_head = node;
    } else {
        Node* curr= StrList->_head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->_next;
        }
        node->_next = curr->_next;
        curr->_next = node;
    }

    StrList->_size++;
}

char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_data;
}

void StrList_print(const StrList* StrList){
	 if (StrList == NULL || StrList->_head == NULL) {
        printf("\n");
        return;
    }
    Node* curr = StrList->_head;
	for(int i=0; i<StrList->_size; i++){
		if(curr->_data != NULL){
			printf("%s", curr->_data);
			if(i < (StrList->_size)-1){
				printf(" ");
			}
		}
		curr = curr->_next;
	}
	printf("\n");
}

void StrList_printAt(const StrList* Strlist, int index) {
    if (Strlist == NULL || Strlist->_head == NULL) {
        return;
    }

    if (index < 0 || index >= StrList_size(Strlist)) {
        return;
    }

    Node* curr = Strlist->_head;
    for (int i = 0; i < index; i++) {
        curr = curr->_next;// Move to the next node
    }

    printf("%s\n",curr->_data);
}


int StrList_printLen(const StrList* Strlist) {
    if (Strlist == NULL || Strlist->_head == NULL) {
        return 0; // List is empty, so return 0 characters
    }

    int sum = 0;
    Node* current = Strlist->_head;
    while (current != NULL) {
        sum += strlen(current->_data); // Add the length of each string to sum
        current = current->_next; // Move to the next node
    }
    return sum;
}

int StrList_count(StrList* StrList, const char* data){
    if(StrList==NULL || StrList->_head==NULL){
        return 0;// List is empty, so return 0 occurrences
    }
    int  count=0;
    Node* curr=StrList->_head;
    while (curr!=NULL) {// Traverse the list
        if (strcmp(curr->_data, data) == 0) { // Compare the current string with the given string
            count++;
        }
        curr=curr->_next;
    }
    return count;
}

void StrList_remove(StrList* Strlist, const char* data) {
    Node* previous = NULL;// Pointer to the previous node
    Node* current = Strlist->_head;

// Traverse the list until the end or until the data is found
    while (current != NULL) {
        // Check if the current node contains the specified data
        if (strcmp(current->_data, data) == 0) {
            if (previous == NULL) {
                // If the node to remove is the head
                Node* tmp = Strlist->_head;
                Strlist->_head = Strlist->_head->_next;// Update the head
                Node_free(tmp);
            } else {
                previous->_next = current->_next;
                Node_free(current);
            }
            Strlist->_size--;
            return; 
        }
          // Move to the next node
        previous = current;
        current = current->_next;
    }
}

void StrList_removeAt(StrList* Strlist, int index) {
    if (index < 0 || (size_t)index >= Strlist->_size) {
        return; // Index out of bounds
    }

    Node* previous = NULL;
    Node* current = Strlist->_head;
    size_t current_index = 0;// Index of the current node

    // Traverse the list until reaching the node at the specified index
    while (current_index < (size_t)index) {
        previous = current;
        current = current->_next;
        current_index++;
    }

    if (previous == NULL) {
        // If removing the head
        Strlist->_head = Strlist->_head->_next;
    } else {
        previous->_next = current->_next;
    }

    Node_free(current);
    Strlist->_size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1 ==NULL || StrList2 ==NULL){
        return false;
    }
  if(StrList1->_size !=StrList2->_size){
      return false;
  }
    Node* curr1 = StrList1->_head;
    Node* curr2 = StrList2->_head;
    // Traverse both lists simultaneously and compare each element
    while (curr1 != NULL && curr2 != NULL){
        // If the data of the current nodes is not equal, the lists are not equal
        if (strcmp(curr1->_data, curr2->_data) != true) {
            return false;
        }
        curr1 = curr1->_next;
        curr2 = curr2->_next;
    }
    return true;
}
StrList* StrList_clone(const StrList* OriginalList){
     if(OriginalList == NULL || OriginalList -> _head == NULL){
         return NULL ; // List is empty or NULL, cannot clone
     }
    // Allocate memory for the new list
    StrList* newList= StrList_alloc();
    if (newList == NULL) {
        return NULL; // Memory allocation failed
    }
    Node* curr= OriginalList->_head;
    while (curr!=NULL){
        // Insert the current data into the cloned list
        StrList_insertLast(newList, curr->_data);
        curr= curr->_next;
    }
    return newList;
}
void StrList_reverse( StrList* StrList){
    if (StrList == NULL || StrList->_head == NULL || StrList->_size <= 1) {
        return; // Empty list or single node, no need to reverse
    }
    Node* curr = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    // Traverse the list and reverse the pointers
    while (curr != NULL) {
        next = curr->_next; // Store the next node
        curr->_next = prev; // Reverse the pointer
        prev = curr; // Move prev to current node
        curr = next; // Move current to next node
    }
    // Update the head of the list
    StrList->_head = prev;
}
// in this method we use selction sort
void StrList_sort( StrList* StrList) {
    if (StrList==NULL || StrList->_size <= 1) {
        return; // No need to sort
    }
    Node* curr = StrList->_head;
    Node* nextNode = NULL;

    // Traverse the list
    while (curr!=NULL){
        nextNode=curr->_next;
        // Traverse the remaining list to find the minimum string
        while(nextNode!=NULL){
            // Compare the strings
            if (strcmp(curr->_data, nextNode->_data) > 0) {
                // Swap the strings
                char* temp= curr->_data;
                curr->_data=nextNode->_data;
                nextNode->_data = temp;
            }
            // Move to the next node
            nextNode = nextNode->_next;
        }
        // Move to the next node
        curr = curr->_next;
    }
}
int StrList_isSorted(StrList* StrList){
    if (StrList == NULL || StrList->_size <= 1) {
        return 1; //No need to check
    }
    Node* curr = StrList->_head;
    Node* nextNode = curr->_next;

    while (nextNode!=NULL){
        // Compare current node's data with the next node's data
        if (strcmp(curr->_data, nextNode->_data) > 0) {
            return false; // List is not sorted
        }
        // Move to the next pair of nodes
        curr = nextNode;
        nextNode = curr->_next;
    }

    // If the loop completes without finding any out-of-order elements, the list is sorted
    return true;
}
