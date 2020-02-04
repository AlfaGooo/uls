#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

void mx_ls_l(){
   struct dirent *e = NULL;
   DIR *r = NULL;
   struct stat *u = NULL;
 
   r = opendir(.);
   while((e = readdir(r)) != NULL) {
       stat(e->d_name, &u);
       printf("%c ",u->st_mode);
       printf("%ld ", u->st_nlink);
        printf("%ld ", u->st_uid);
	printf("%ld ", u->st_gid);
       printf("%ld",u->st_size);
       printf("%s ", u->st_mtime);// time of changing not time of creating
       printf("%s\n", e->d_name);
      
   }
    closedir(.);
 
}

