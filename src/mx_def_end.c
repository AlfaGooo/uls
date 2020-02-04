#include <stdbool.h>
bool mx_isspace(char c) ;

int mx_def_end(const char *str, int sz) {
    int end = 0;

    for (int a = sz - 1; a > 0; a--) {
        if (mx_isspace(str[a]) == false) {
            end = a;
            a = 0;
        }
    }
    return end;
}

