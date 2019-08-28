/* sumdig.c
A C executable treats its command-line arguments as strings.
Write a program that sums all the digits (0 ... 9) that appear in all its command-line arguments.
 - all characters in the arguments that are not digits should be ignored
 - if there are no arguments, the program does nothing
Possible executions are:
prompt$ ./sumdig
prompt$ ./sumdig 12 34
10
prompt$ ./sumdig 1u1u 1u11aby
5
prompt$ ./sumdig 1 --2-- ++3++
6
prompt$ ./sumdig 000410002003
10
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
