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
    tList* lists; 
    bool (*compare)();
    int (*hash)();
    int size;

}*tHashTable;

/* purpose: Delete an item from the Hashtable
 * input:   HashTable and the item to be deleted
 * output:  the Hashtable with the item deleted if it is presenent
 */
tHashTable ht_delete(tHashTable t, void* v)
{
    int to_insert = *(int *) v;
    int mod = to_insert % 5;
    tList buff = check_malloc(sizeof(tList));
    buff = list_remove(t->lists[mod], v, t->compare);
    if( buff == NULL)
    {
        return t;
    }

    else
    {
        t->lists[mod] = buff;
    }
    return t;
}

/* purpose: apply a function to each element in the hashtable
 * input:   hashtable and the function
 * output:  nothing
 */
void ht_foreach(tHashTable t, void (*function)())
{
    int count;
    for(count = 0; count < t->size; count++)
    {
        list_foreach(t->lists[count], function);
    }
}

/* purpose: apply a function with a parameter to each element in the hashtable
 * input:   hashtable, the function, and the parameter
 * output:  nothing
 */
void ht_foreach1(tHashTable t, void (*function)(void *, void *), void* param)
{
    int count;
    for(count = 0; count < t->size; count++)
    {
        list_foreach1(t->lists[count], function, param);
    }
}

/* purpose: apply a function with two parameter to each element in the hashtable
 * input:   hashtable, the function, and two parameter
 * output:  nothing
 */
void ht_foreach2(tHashTable t, void (*function)(void*, void*, void*), void* param1, void* param2)
{
    int count;
    for(count = 0; count < t->size; count++)
    {
        list_foreach2(t->lists[count], function, param1, param2);
    }
}

/* purpose: Free the hashtable
 * input:   the hashtable
 * output:  nothing
 */
void ht_free(tHashTable t)
{
    for(int count = 0; count < t->size - 1; count++)
    {
        printf("Hello\n");
        free(t->lists[count]);
    }
    free(t);
}

/* purpose: creates new hastable
 * input:   nothing
 * output:  a new hashtable
 */
tHashTable ht_initialize(int i, bool (*compare_function)(), int(*hash_function)())
{
    tHashTable table;
    table->size = check_malloc(sizeof(int));
    table->size = i;
    table = (tHashTable) (check_malloc(sizeof(tHashTable)));
    table->compare = (check_malloc(sizeof(compare_function)));
    table->compare = compare_function;
    table->hash = (check_malloc(sizeof(hash_function)));
    table->hash = hash_function;
    table->lists = (tList*) (check_malloc(sizeof(tList*)));

    int j;
    for(j = 0; j < i; j++)
    {
        table->lists[j] = (tList) list_initialize();
    }

    return table;

}

/* purpose: insert a number into the hashtable
 * input:   the hashtable and a value
 * output:  the new hashtable with the value inserted
 */
tHashTable ht_insert(tHashTable t, void* v )
{
    int to_insert = *(int *) v;
    int mod = to_insert % 5;
    t->lists[mod] = list_insert_beginning(t->lists[mod], v);
    return t;
}

/* purpose: looks up an element in the hashtable
 * input:   Hashtable and element to lookup
 * output:  Null if not found, and if found the element
 */
void *ht_lookup(tHashTable t, void* v)
{
    int to_insert = *(int *) v;
    int mod = to_insert % 5;
    bool buff = check_malloc(sizeof(bool));
    buff = list_member(t->lists[mod], v, t->compare);
    if( buff == false)
    {
        return NULL;
    }

    else
    {
        return v;
    }
    
}

/* purpose: Print the hashtable
 * input:   Hashtable and print function
 * output:  prints the hashtable
 */
void ht_print(tHashTable t, void (*print_function)(void* v, bool b))
{
    int count;
    void *buffer1;
    for(count = 0; count < t->size; count++)
    {
        list_foreach1(t->lists[count],  print_function, buffer1);
    }
}