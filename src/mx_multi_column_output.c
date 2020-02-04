#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_free_array2(char **arr, int row); 
int mx_bubble_sort(char **arr, int size);
static int *make_titi(int c, char **yy);
static void sorting_dop(int y, int c, int *titi, char **yy);
char *mx_strcat(char *restrict s1, const char *restrict s2);
void mx_push_back(t_list **list, void *data); 
int mx_list_size(t_list *list);

typedef struct s_list {
    void *data;
    struct s_list *next;
}   t_list;

void mx_multi_column_output(int y, DIR *r) {
    struct dirent *e = NULL;
    int c = 0;
    char **yy = NULL;
    int b = 0;
    int *titi = NULL;
    t_list *temp = NULL;
    t_list *consis = NULL;
    //for (; (e = readdir(r)) != NULL; c++);
    //yy = (char**)malloc (sizeof(char**) * c); //костыль нужно вернуться к си
    e = readdir(r);
    while (e != NULL) {
        mx_push_back(&consis, (void*)e);
        //e = readdir(r);
        //yy[b] = mx_strnew(mx_strlen(e->d_name));
        //yy[b] = e->d_name;
        //b++;
        e = readdir(r);
   }
   c = mx_list_size(consis);
   yy = (char **)malloc(sizeof(char **) * c);
   temp = consis;
   int a = -1;
   for (b = 0; b < c; b++) {
        if ((((struct dirent *)(consis->data))->d_name)[0] != '.') {
            a++;
            yy[a] = mx_strnew(mx_strlen(((struct dirent *)(consis->data))->d_name));
            yy[a] = mx_strcat(yy[a], ((struct dirent *)(consis->data))->d_name);
        }
        consis = consis -> next;

    }   
    c = a + 1 ;
    //yy[c] = NULL; 
    closedir(r);
    mx_bubble_sort(yy, c);
    titi = make_titi(c, yy);
    sorting_dop(y, c, titi, yy);
 }

static int *make_titi(int c, char **yy) {
    int b = 0;
    int *titi = NULL;

    titi = (int *)malloc(sizeof(int *) * c);
    for (b = 0; b < c; b++)
       titi[b] = mx_strlen(yy[b]);
    return titi;
}

static void sorting_dop(int y, int c, int *titi, char **yy) {
    int rest = y + 1;
    //int con = 0;
    int max = 0;
    int b = 0;
    int counter = 0;
    int *len = NULL;
    int col = 0;

    while (rest > y && counter < c) {
        rest = 0;
        counter++;
        col = -1;
        if (len)
            free(len);
        len = (int*)malloc(sizeof(int*) * ((c + 1) / counter));
        for(int a =  0; a < c; a++) {
            col++;
            max = 0;
            for( b = a; b < a + counter && b < c; b++)
                if(titi[b] > max)
                    max = titi[b];
            a = b - 1;
            len[col] = max;
            rest = rest + max;
            if(b < c) {
                rest = rest + 2;
                len[col] = len[col] + 2;
            }
        }
    }        
   
    int term;
    term = isatty(1); 

    for (b = 0; b < counter; b++) {
        int a = 0;
        for (col = b; col < c; col = col + counter) {
            write(1, yy[col], mx_strlen(yy[col]));
            if (mx_strlen(yy[col]) < len[a]) 
                for (rest = 0; rest < len[a] - mx_strlen(yy[col]); rest++)
                    write(1, " ", 1);

            a++;
        }
        write(1, "\n",1);
    }
    free(titi);
    mx_free_array2(yy, c);
}
//clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o n main.c mx_standart_ls.c
// mx_multi_column_output.c mx_push_back.c mx_list_size.c mx_strlen.c 
//mx_strnew.c mx_strcat.c mx_bubble_sort.c mx_free_array2.c mx_strcmp.c mx_create_node.c
