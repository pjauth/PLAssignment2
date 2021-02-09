//Patrick Auth
//This is my code

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "misc.h"
#include "ht.h"
#include "list.h"

typedef struct sHashTable  
{
    tList** lists; 

}*tHashTable;

/* purpose: 
 * input:   
 * output:  
 */
tHashTable ht_delete(tHashTable t, void* v)
{

    return t;
}

/* purpose: 
 * input:   
 * output:  
 */
void ht_foreach(tHashTable t, void (*function)(void *))
{

}

/* purpose: 
 * input:   
 * output:  
 */
void ht_foreach1(tHashTable t, void (*function)(void *, void *), void* v)
{

}

/* purpose: 
 * input:   
 * output:  
 */
void ht_foreach2(tHashTable t, void (*function)(void *, void *, void *), void* v, void* r)
{

}

/* purpose: 
 * input:   
 * output:  
 */
void ht_free(tHashTable t)
{

}

/* purpose: creates new hastable
 * input:   nothing
 * output:  a new hashtable
 */
tHashTable ht_initialize(int i, bool (*compare_function)(), int(*hash_function)())
{
    tHashTable table;
    table = (tHashTable) (check_malloc(sizeof(tHashTable)));

    int j;
    for(j = 0; j < i; j++)
    {
        *(table->lists[j]) = (tList) (check_malloc(sizeof(tList)));
        table->lists[j] = (tList*) list_initialize();
    }

    return table;

}

/* purpose: 
 * input:   
 * output:  
 */
tHashTable ht_insert(tHashTable t, void* v )
{
    return t;
}

/* purpose: 
 * input:   
 * output:  
 */
void *ht_lookup(tHashTable t, void* v)
{
    return v;
}

/* purpose: 
 * input:   
 * output:  
 */
void ht_print(tHashTable t, void (*print_function)(void*, bool))
{

}