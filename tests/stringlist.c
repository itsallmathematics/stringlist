#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringlist.h"
//StringList "Vector" type for C
//Original Author: Philip Bohun
//Modified by: itsallmathematics
//Free ALL memory
void sl_destroy(StringList *pSl)
{
    assert(pSl);
    size_t i;
    //First free all strings
    for(i = 0; i < pSl->size; i++)
    {
        free(pSl->data[i]);
        pSl->data[i] = NULL;
    }
    //Free the pointer to the array of strings
    free(pSl->data);
    pSl->data = NULL;
    //Free StringList pointer itself
    pSl = NULL;
    free(pSl);
}
void sl_remove(StringList *pSl, size_t const index)
{
    assert(pSl);
    size_t i;
    free(pSl->data[index]);
    pSl->data[index] = NULL; // "mark" the ptr as NULL
    // relink the list such that the destroyed string is removed entirely to prevent NULL dereference/Double Free upon destroy
    for(i = index; i < pSl->size - 1; i++)
    {
        pSl->data[i] = pSl->data[i+1];
    }
    pSl->data[pSl->size--] = NULL;
}
void sl_print(StringList *pSl)
{
    assert(pSl);
    size_t i;
    for(i = 0; i < pSl->size; i++)
    {
        printf("%s\n", pSl->data[i]);
    }
}
//Mission: To return a pointer to a StringList
StringList* sl_new(void)
{
    StringList *pSl = malloc(sizeof(StringList));
    if(!pSl)
    {
        return NULL;
    }
    pSl->size = 0;
    pSl->capacity = 1;
    pSl->data = malloc(sizeof(char*)); // New up a POINTER
    if(!pSl->data)
    {
        free(pSl);
        return NULL;
    }
    return pSl;
}
void sl_push(StringList *pSl, const char *str)
{
    assert(pSl && str);
    if(pSl->size + 1 > pSl->capacity)
    {
        pSl->capacity *= 2;
        pSl->data = realloc(pSl->data, pSl->capacity * sizeof(char *));
    }
        pSl->data[pSl->size] = malloc(strlen(str) + 1);
        strcpy(pSl->data[pSl->size++], str);
}
int sl_find(const StringList *pSl, const char *str)
{
    assert(pSl && str);
    size_t i;
    for(i = 0; i < pSl->size; i++)
    {
        if(strcmp(pSl->data[i], str) == 0) return i;
    }
    return -1;
}