#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
//#include <string.h>
#include <sys/acl.h>

void mx_ls_l(){
   struct dirent *e = NULL;
   DIR *r = NULL;
   struct stat *u = NULL;
   //struct passwd *t = NULL;
   //struct group *i = NULL;
 
   r = opendir(".");
   u = (struct stat *)malloc(sizeof(struct stat *));
   while((e = readdir(r)) != NULL) {
    //if(mx_strncmp(e->d_name ,".", 1) != 0) {
       stat(e->d_name, u);
       printf("%c ",e->d_type);
       printf("%s ",acl_get_file(e->d_name, acl_type_t type));
        printf("%c ",u->st_mode);
        printf("%hu ", u->st_nlink);
        //t = getpwuid(u->st_uid);
       // printf("%s ", t->pw_name);
        //i = getgrgid(u->st_gid);
       // printf("%s ", i->gr_name);
        printf("%lld ",u->st_size);
       // printf("%s ", ctime(&u->st_birthtime));// time of changing not time of creating
        printf("%s\n", e->d_name);
        //closedir(r);
      }
  // }
 //closedir(r);
}
