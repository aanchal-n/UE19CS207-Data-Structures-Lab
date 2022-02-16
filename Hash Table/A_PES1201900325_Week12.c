#include "hash.h"
HashTable *create_table(int size)
{
    HashTable *new_table= (HashTable*)malloc(sizeof(HashTable));
    int *array = (int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        array[i]=-1;
    }
    new_table->table = array;
    new_table->size = size;
    
    return new_table;
}

void insert(HashTable *htable, int element)
{
    int current_hashindex=(element%(htable->size));

    while(htable->table[current_hashindex]!=-1)
    {
        ++current_hashindex;
        current_hashindex%=(htable->size);
    }

    htable->table[current_hashindex]=element;
}

int search(HashTable *htable, int element)
{
    int index = element%(htable->size);

    while(htable->table[index]!=-1)
    {
        if (htable->table[index] == element)
        {
            return 1;
        }
        ++index;
        index%=(htable->size);
    }
    return 0;
}

void delete (HashTable *htable, int element)
{
    int index = element%(htable->size);

    while (htable->table[index]!=-1)
    {
        if (htable->table[index]==element)
        {
            htable->table[index]=-1;
        }
        ++index;
        index%=(htable->size);
    }
    
}


void destroy_table(HashTable *htable)
{
    free(htable);

}
