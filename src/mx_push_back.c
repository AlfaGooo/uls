#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

t_list *mx_create_node(void *data);

void mx_push_back(t_list **list, void *data) {
    
    if(list == NULL)
        return;
    t_list *p = mx_create_node(data);

    if (p == NULL)
        return;
    p -> data = data;
    p -> next = NULL;
   if (*list == NULL)
        *list = p;
    else {
        t_list *bi = *list;
        
        while (bi->next != NULL)
            bi = bi->next;
        bi->next = p;
    }
}

