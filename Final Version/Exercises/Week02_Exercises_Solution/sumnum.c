// sumnum.c: sum the numbers on the command line
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc > 1) {
      int i, n;
      int sum = 0;
      for (i=1; i<argc; i++) {
         if (sscanf(argv[i], "%d", &n) != 1) {
            fprintf(stderr, "error: argument %s is non-numeric\n", argv[i]);
            return EXIT_FAILURE;
         }
         sum = sum + n;
      }
      printf("%d\n", sum);
   }
   return EXIT_SUCCESS;
}
