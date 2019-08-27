/* sumdig.c
   sum all the digits in all the command line arguments
   do nothing if there are no arguments
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   if (argc > 1) {
       int sum = 0;
       for (int arg = 1; arg < argc; arg++) {
           char *s = argv[arg];
           while (*s != '\0') {
               if ('0'<=*s && *s<='9') {
                   sum += (*s - '0');
               }
               s++;
           }
       }
       printf("%d\n", sum);
   }
   return EXIT_SUCCESS;
}
