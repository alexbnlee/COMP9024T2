// base2.c
// Convert the number argv[1] to base 2
// Usage message  generated if argv[1] not read properly
// Uses the quack ADT, compile using 'dcc quack.cc base2.c'

#include <stdlib.h>
#include <stdio.h>
#include "quack.h"

int main(int argc, char *argv[]) {
   int num, base=2;

   if ((argc == 2) &&
       (sscanf(argv[1], "%d", &num) == 1) &&
       (num >= 0)) {

       Quack s = createQuack();
       while (num > 0) {
          push(num % base, s);
          num = num / base;
       }
       if (isEmptyQuack(s)) {
          printf("0"); // num was 0
       }
       else {
          while (!isEmptyQuack(s)) {
             printf("%d", pop(s)); // will be 0 or 1
          }
       }
       putchar('\n');
       return EXIT_SUCCESS;
   }
   else {
       printf("Usage: %s number\n", argv[0]);
       return EXIT_FAILURE;
   }
}
