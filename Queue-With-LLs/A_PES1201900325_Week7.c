#include "queue.h"

static node *create_node(int id, int time, node *link)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->id = id;
    new_node->time = time;
    new_node->link = link;
    
    return new_node;
}

void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->tail = NULL;
    ptr_list->number_of_nodes = 0;
}

const int node_get_id(node *node_ptr)
{
    return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
    return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->id = id;
    new_node->time = time;
    new_node->link = NULL;
    
    if (!ptr_list->number_of_nodes)
    {
        ptr_list->head = ptr_list->tail = new_node;
    }
    else
    {
        ptr_list->tail->link = new_node;
        ptr_list->tail = new_node;
    }
    ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
    node *delete_node = ptr_list->head;
    if (ptr_list->number_of_nodes != 0)
    {
        ptr_list->head = delete_node->link;
        ptr_list->number_of_nodes--;
        free(delete_node);
    }
}

void list_destroy(List *ptr_list)
{
    while (ptr_list->number_of_nodes > 0)
    {
        node *temp_var = ptr_list->head;
        ptr_list->head = ptr_list->head->link;
        free(temp_var);
        ptr_list->number_of_nodes--;
    }
    free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
    List *dummy_list = malloc(sizeof(List));
    list_initialize(dummy_list);
    queue_list->ptr_list = dummy_list;
}

void queue_enqueue(Queue *ptr, int id, int time)
{
    list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
    list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void queue_peek(Queue *ptr)
{
    if (queue_is_empty(ptr)==0)
    {
        printf("Empty Queue \n");
    }
    else
    {
        printf("%d %d \n",ptr->ptr_list->head->id,ptr->ptr_list->head->time);
    }
}

void queue_destroy(Queue *ptr)
{
    list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
    int time_dummy = 0;
    int id_dummy = 0;
    
    while (time_dummy < t)
    {
        if (queue_is_empty(ptr_queue)==0)
        {
            printf("Empty Queue \n");
            return 0;
        }
        
        time_dummy += node_get_time(ptr_queue->ptr_list->head);
        
        if (time_dummy > t)
        {
            break;
        }
        
        if (ptr_queue->ptr_list->number_of_nodes != 0)
        {
            node *temp_node = ptr_queue->ptr_list->head;
            ptr_queue->ptr_list->head = ptr_queue->ptr_list->head->link;
            free(temp_node);
            ptr_queue->ptr_list->number_of_nodes--;
        }
    }
        
    if (queue_is_empty(ptr_queue) == 0)
    {
        printf("Empty Queue \n");
        return 0;
    }
        
    id_dummy = ptr_queue->ptr_list->head->id;
    printf("%d \n",id_dummy);
    return 0;
}

