#ifndef StringList_H
    #define StringList_H
    typedef struct _StringList
    {
        char **data;
        size_t capacity;
        size_t size;
    } StringList;
StringList* sl_new(void);
    void sl_push(StringList *pSl, const char* str);
    int sl_find(const StringList *pSl, const char *str);
    void sl_print(StringList *pSl);
    void sl_remove(StringList *pSl, size_t const index);
    void sl_destroy(StringList *pSl);
#endif