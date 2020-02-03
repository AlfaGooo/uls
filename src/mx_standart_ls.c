#include <sys/ioctl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>


void mx_multi_column_output(int y, DIR *r);

void mx_standart_ls() {
    DIR* r = NULL;
    //struct dirent *e = NULL;
    struct winsize wine;

    r = opendir(".");
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wine);
    mx_multi_column_output(wine.ws_col, r);
    closedir(r);
}
