#include "standard.h"
#include "stringlist.h"
MAIN_V
{
    StringList *pList = sl_new();
    sl_push(pList, "hello");
    sl_push(pList, "go away");
    sl_push(pList, "goodbye");
    sl_remove(pList, 1);
    sl_print(pList);
    int test = sl_find(pList, "go away");
    printf("Test #1 find result: %d\n", test);
    test = sl_find(pList, "hello");
    printf("Test #2 find result: %d\n", test);
    sl_destroy(pList);
    RES;
}
