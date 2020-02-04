#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

t_list *mx_create_node(void *data);

void mx_push_front(t_list **list, void *data) {
    t_list *u = NULL;

    if (list == NULL)
        return;
    u = mx_create_node(data);
    if (!u)
        return;
    u -> data = data;
    u -> next = *list;
    *list = u;
}

