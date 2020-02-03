#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static char *loose_slash(char *w);

void mx_output_mistake1(char *n, char *n, DIR *r, int fd) {
	char *t = NULL;

	if (r == NULL && fd < 0) {
       closedir(r);
       close(fd);
       t = loose_slash(argv[0]);
       write(2, t, mx_strlen(t));
       free(t);
       write(2, ": ", 2);
       write(2, argv[1], mx_strlen(argv[1]));
       write(2, ": ", 2);
       write(2, strerror(2), mx_strlen(strerror(2)));
       write(2, "\n", 1);
       exit(0);
       }
}

static char *loose_slash(char *w) {
    int r = 0;
    int y = 0;
    char *u = NULL;
 
    u = mx_strnew(6);
    y = mx_strlen(w);
    for (r = y - 1; r >= 0; r--) {
        if (w[r]=='/')
            break;
        if (w[r] != '/')
            u[y - r - 1] = w[r];
    }
   return u;
}
