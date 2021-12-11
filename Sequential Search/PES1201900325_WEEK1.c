//Implementation for session1_seq_search.h
#include "ss.h"
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
	{
        int cur_index=0;
        for (;cur_index<=n;cur_index++)
        {
            if (arr[cur_index]==key)
            {
                cur_index++;
                break;
            }
            
            if (cur_index==(n-1))
            {
                cur_index=-1;
                break;
            }
        }
        return cur_index;
	}
