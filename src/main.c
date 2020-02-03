#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <stdlib.h>

void mx_standart_ls();

int main(int argc, char *argv[]) {
   //DIR* r = NULL;
   //int fd = -1;
   //struct winsize wine;
   //struct dirent *e = NULL;
   //int yupi = 0;
   //char *t = NULL;
	if(argv[0]){
    if(argc == 1)
   		mx_standart_ls();
   }
   	return 0;
   }
    /*if(ls + cat)
    	mx_ks_cat()

//fd = open(argv[0], O_RDONLY)
//  write(1,argv[0],mx_strlen(argv[0]))
  
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &wine);
   char *rn = mx_itoa(wine.ws_row);
   //write(1,rn,mx_strlen(rn));
   //write(1,"\n",1);
   free(rn);
   rn = mx_itoa(wine.ws_col); //ширина
   //int pup = mx_strlen(rn);
   //write(1,rn,mx_strlen(rn));
   //write(1,"\n",1);
   free(rn);
   multi_column_output(wine.ws_col, r);
   if (argc > 1)
       r = opendir(argv[1]);
   if (!r)
       fd = open(argv[1], O_RDONLY);
   if (r == NULL && fd < 0) {
  
   if (r != NULL) {
       while ((e = readdir(r)) != NULL) {
           if (e->d_name[0] == '.');
           else {
               yupi = yupi + 2;
               write(1, e->d_name, mx_strlen(e->d_name));
               yupi = yupi + mx_strlen(e->d_name);
               write(1, "\n", 1);
           }  
       }
   }
  
   if (fd >= 0) {
       write(1, argv[1], mx_strlen(argv[1]));
       write(1, "\n", 2);
   }
   close(fd); 
   closedir(r);
   mx_ls_l(argv[1]);
   //system("leaks n -q");
   return 0;
}*/

 
