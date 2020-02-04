#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

void mx_pop_front(t_list **head) {
    if (*head == NULL || head == NULL)
        return;
    t_list *p = (*head) -> next;

    free(*head);
    *head = p;
}
