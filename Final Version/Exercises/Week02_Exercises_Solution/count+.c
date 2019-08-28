// count+.c: iteratively count from 0 to argv[1], where argv[1] is +ive
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   int endcount = 0;

   if ((argc != 2) || (sscanf(argv[1], "%d", &endcount) != 1)) {
      fprintf(stderr, "Usage: %s number\n", argv[0]);
      return(EXIT_FAILURE);
   }
   else {
      int i;
      for (i=0; i<=endcount; i++) {
         printf("%d", i);
         if (i < endcount) {
            putchar(',');
         }
         else {
            putchar('\n');
         }
      }
      return EXIT_SUCCESS;
   }
}
