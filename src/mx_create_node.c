#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

t_list *mx_create_node(void *data) {
    t_list *p = malloc(sizeof(t_list));

    if (!p) 
        return NULL;
    p -> data = data;
    p -> next = NULL;
    return p;
}

