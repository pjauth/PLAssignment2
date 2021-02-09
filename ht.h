/* ht.h */


#ifndef _HT
#define _HT

#include <stdbool.h>

typedef struct sHashTable  *tHashTable;

/* exported functions */
/* [[ consider first producing a header comment for each function below. ]] */

tHashTable ht_delete(tHashTable, void*);
void       ht_foreach(tHashTable, void (*function)(void *));
void       ht_foreach1(tHashTable, void (*function)(void *, void *), void*);
void       ht_foreach2(tHashTable, 
                       void (*function)(void *, void *, void *), 
                       void*, void*);
void       ht_free(tHashTable);
tHashTable ht_initialize(int, 
                         bool (*compare_function)(),
                         int(*hash_function)());
tHashTable ht_insert(tHashTable, void*);
void       *ht_lookup(tHashTable, void*);
void       ht_print(tHashTable, void (*print_function)(void*, bool));

#endif
