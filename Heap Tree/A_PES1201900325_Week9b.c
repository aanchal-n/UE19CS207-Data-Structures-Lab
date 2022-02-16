#include "heap.h"

int parent(int i)
{
    return ((i-1)/2);
}

void Heapify(heap* tmp,int i)
{
    int right_node = 2*i + 2;
    int left_node = 2*i +1;
    
    int cur_min = i;
    
    if (left_node< tmp->size && tmp->elements[left_node]< tmp->elements[i])
    {
        cur_min = left_node;
    }
    if (right_node < tmp->size && tmp->elements[right_node] < tmp->elements[cur_min])
    {
        cur_min = right_node;
    }
    if (cur_min!=i)
    {
        int temp = tmp->elements[i];
        tmp->elements[i] = tmp->elements[cur_min];
        tmp->elements[cur_min] = temp;
        Heapify(tmp,cur_min);
    }
}

heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    free(tmp);
}
int heap_get_capacity(heap* tmp){
    return (tmp->capacity);
}
int heap_get_size(heap* tmp){
    return (tmp->size);
}

int heap_insert(heap* tmp,int data){
    if (tmp->size == tmp->capacity)
    {
        return 0;
    }
    tmp->size++;
    int cur_pos = tmp->size - 1;
    tmp->elements[cur_pos] = data;
    
    
    while(cur_pos != 0 && (tmp->elements[parent(cur_pos)] > tmp->elements[cur_pos]))
    {
        int temp = tmp->elements[cur_pos];
        tmp->elements[cur_pos] = tmp->elements[parent(cur_pos)];
        tmp->elements[parent(cur_pos)] = temp;
        
        cur_pos = parent(cur_pos);
    }
    return 1;
}

int heap_get_min(heap* tmp){
    return tmp->elements[0];
}
void heap_remove(heap* tmp){
    if (tmp->size == 0)
    {
        return;
    }
    else if (tmp->size == 1)
    {
        tmp->size--;
        return;
    }
    
    tmp->elements[0] = tmp->elements[(tmp->size)-1];
    tmp->size--;
    
    Heapify(tmp,0);
}



