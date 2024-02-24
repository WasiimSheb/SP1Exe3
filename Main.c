#include <stdio.h>
#include "StrList.h"
#define V 100

int main() {
    StrList* strList = StrList_alloc();
    int c = 1;
    char v[V];
    int x, y;

    while(c != 0) {

        scanf("%d", &c);

        switch (c) {
            case 0:
                StrList_free(strList);
                return 0;
            case 1:
                scanf("%d", &y);
                for (int i = 0; i < y; ++i) {
                    scanf("%s", v);
                    StrList_insertLast(strList, v);
                }
                break;
            case 2:
                scanf("%d", &x);
                scanf("%s", v);
                StrList_insertAt(strList, v, x);
                break;
            case 3:
                StrList_print(strList);
                break;
            case 4:
                printf("%zu\n", StrList_size(strList));
                break;
            case 5:
                scanf("%d", &x);
                StrList_printAt(strList, x);
                break;
            case 6:
                printf("%d\n", StrList_printLen(strList));
                break;
            case 7:
                scanf("%s", v);
                printf("%d\n", StrList_count(strList, v));
                break;
            case 8:
                scanf("%s", v);
                StrList_remove(strList, v);
                break;
            case 9:
                scanf("%d", &x);
                StrList_removeAt(strList, x);
                break;
            case 10:
                StrList_reverse(strList);
                break;
            case 11:
                StrList_free(strList);
                break;
            case 12:
                StrList_sort(strList);
                break;
            case 13:
                if (StrList_isSorted(strList) == 1) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
        }
    }

    return 0;
}
