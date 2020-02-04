 
 
 #include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <linux/posix_acl_xattr.h>
//#include <string.h>
 
char *mx_strtrim(const char *str);

void mx_ls_l(){
   struct dirent *e = NULL;
   DIR *r = NULL;
   struct stat u;
   struct passwd *t = NULL;
   struct group *i = NULL;
   char *times = NULL;
   
   r = opendir(".");
   //u = (struct stat *)malloc(sizeof(struct stat *));
   while((e = readdir(r)) != NULL) {
    //if(mx_strncmp(e->d_name ,".", 1) != 0) {
       stat(e->d_name, &u);
       printf("%c ",e->d_type);
       //printf("%s ",acl_get_file(e->d_name, acl_type_t type));
        printf("%c ",u.st_mode);
       // if(((u.st_mode)&&S_IFMT) == S_IFREG)
       //  printf("regular file ");
        printf("%ld ", u.st_nlink);
        t = getpwuid(u.st_uid);
        printf("%s ", t->pw_name);
        i = getgrgid(u.st_gid);
        printf("%s ", i->gr_name);

        printf("%ld ",u.st_size);

        times = ctime(&u.st_ctime); 
        times = mx_strtrim(times);
        //times = ctime(&rawtime);
        printf("%s ", times);// time of changing not time of creating
        free(times);
        //free(times);
        printf("%s\n", e->d_name);
        //closedir(r);
      }
  // }
 //closedir(r);
}
