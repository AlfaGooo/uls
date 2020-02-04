#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

int mx_list_size(t_list *list) {
    int size = 1;

    if (list == NULL)
        return 0;
    t_list *tempor = list;
    
    while (tempor -> next != NULL) {
        tempor = tempor -> next;
        size++;
    }
    return size;
}


