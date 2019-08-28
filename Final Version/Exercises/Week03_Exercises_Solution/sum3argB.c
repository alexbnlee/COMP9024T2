// sum3argB.c: sum 3 arguments from the command line using atoi()
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc == 4) {
       printf("%d\n", atoi(argv[1]) + atoi(argv[2]) + atoi(argv[3]));
   }
   return EXIT_SUCCESS;
}
// atoi() does no error detection: it simply returns 0 if its argument is non-integer.
// This means that the command './sum3argB.c 1 z 3' will output 4
