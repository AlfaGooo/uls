#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL)
        return;
    if ((*head) -> next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    t_list *last = *head;

    while (last -> next -> next != NULL)
        last = last -> next;
    free(last -> next);
    last -> next = NULL;
}
