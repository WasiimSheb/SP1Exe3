#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100//maximum number of words 

int main(){
    int option;
    char data[MAX];
    StrList* list = StrList_alloc();

    while(1){
        if (scanf("%d", &option) != 1) {
            printf("Invalid choice. Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (option) {
            case 1: {//insert strings
                int count;
                if (scanf("%d", &count) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                for (int i = 0; i < count; i++) {
                    if (scanf("%s", data) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    StrList_insertLast(list, strdup(data)); // Copy data before insertion
                }
                break;
            }
            case 2: {//Insert a string at a specific index
                int index;
                if (scanf("%d", &index) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                if (scanf("%s", data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                StrList_insertAt(list, strdup(data), index); // Copy data before insertion
                break;
            }
            case 3://print the list
                StrList_print(list);
                break;
            case 4://Print the size of the list
                printf("%zu\n", StrList_size(list));
                break;
            case 5: {//Print the string at a specific index
                int index;
                if (scanf("%d", &index) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                StrList_printAt(list, index);
                break;
            }
            case 6://print the length of the list
                printf("%d\n", StrList_printLen(list));
                break;
            case 7://Count occurrences of a string
                if (scanf("%s", data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("%d\n", StrList_count(list, data));
                break;
            case 8:// Remove all occurrences of a string
                if (scanf("%s", data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                StrList_remove(list, data);
                break;
            case 9: {//Remove the string at a specific index
                int index;
                if (scanf("%d", &index) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                StrList_removeAt(list, index);
                break;
            }
            case 10://Reverse the list
                StrList_reverse(list);
                break;
            case 11://Clear the list
                StrList_free(strList);
                break;
	        }
            case 12://Sort the list
                StrList_sort(list);
                break;
            case 13://Check if the list is sorted
                printf("%s\n", StrList_isSorted(list) ? "true" : "false");
                break;
            case 0://Exit
                StrList_free(list);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}
