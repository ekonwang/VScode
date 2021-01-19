#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE *fp;

   printf("This text is redirected to stdout\n");

   fp = freopen("file.txt", "w+", stdout);

   printf("This text is redirected to file.txt\n");

   fclose(fp);
   
   system("pause");
   return(0);
}