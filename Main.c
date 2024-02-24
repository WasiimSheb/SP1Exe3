// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "StrList.h"
// #define V 100

// int main() {
//     StrList* strList = StrList_alloc();
//     int c ;
//     char v[V];
//     int x, y;

//     while(1) {

//         if(scanf("%d", &c)!=1){
//             printf("invalid choise");
//              while (getchar() != '\n');
//              continue;
//         }

//         switch (c) {
//             case 0:
//                 StrList_free(strList);
//                 return 0;
//             case 1:
//                 scanf("%d", &y);
//                 for (int i = 0; i < y; ++i) {
//                     scanf("%s", v);
//                     StrList_insertLast(strList, v);
//                 }
//                 break;
//             case 2:
//                 scanf("%d", &x);
//                 scanf("%s", v);
//                 StrList_insertAt(strList, v, x);
//                 break;
//             case 3:
//                 StrList_print(strList);
//                 break;
//             case 4:
//                 printf("%zu\n", StrList_size(strList));
//                 break;
//             case 5:
//                 scanf("%d", &x);
//                 StrList_printAt(strList, x);
//                 break;
//             case 6:
//                 printf("%d\n", StrList_printLen(strList));
//                 break;
//             case 7:
//                 scanf("%s", v);
//                 printf("%d\n", StrList_count(strList, v));
//                 break;
//             case 8:
//                 scanf("%s", v);
//                 StrList_remove(strList, v);
//                 break;
//             case 9:
//                 scanf("%d", &x);
//                 StrList_removeAt(strList, x);
//                 break;
//             case 10:
//                 StrList_reverse(strList);
//                 break;
//             case 11: // Clear the list
//                 while (StrList_size(strList) > 0) {
//                     StrList_removeAt(strList, 0);
//                 }
//                 break;
//             case 12:
//                 StrList_sort(strList);
//                 break;
//             case 13:
//                 if (StrList_isSorted(strList) == 1) {
//                     printf("true\n");
//                 } else {
//                     printf("false\n");
//                 }
//                 break;
//             default:
//                 printf("Invalid choice. \n");
//                 break;      
//         }
//     }

//     return 0;
// }

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
            case 11: // Clear the list
                 while (StrList_size(list) > 0) {
                     StrList_removeAt(list, 0);
                 }
                 break;
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
