/* nth.c:
Write a C program called nth.c that prints every n-th character in a string, where:
  - the number n is a command-line argument and
  - the string is on stdin
For example,
If n=1 then every character in the string is printed.
If n=2 then every second character is printed.
If n=5 then every fifth character is printed, and so on.
If n is greater than the string length, nothing is printed.

In all other circumstances, e.g. no input, or the command-line argument is 0,
or the wrong number of command line arguments,
the program does nothing (it simply returns and does not generate an error message).
You may assume that the string is never more than 100 characters long.

For example, if a test file test.inp contains the string 9024datamanavatar
then the following executions are possible:

prompt$ ./nth < test.inp
prompt$

prompt$ ./nth 2 1 3 < test.inp
prompt$

prompt$ ./nth 0 < test.inp
prompt$

prompt$ ./nth 1 < test.inp
9024datamanavatar

prompt$ ./nth 2 < test.inp
04aaaaaa

prompt$ ./nth 5 < test.inp
dat

prompt$ ./nth 17 < test.inp
r

prompt$ ./nth 50 < test.inp
prompt$
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc == 2) {
      int n = 0;
      if (sscanf(argv[1], "%d", &n) == 1 && n != 0) {
         char s[100];
         if (scanf("%s", s) == 1) {
             int f = 0; // found something to print
             int i = 1;
             while (s[i-1] != '\0') {
                if (i%n == 0) {
                    putchar(s[i-1]);
                    f = 1;
                }
                i++;
             }
             if (f) {
                 putchar('\n');
             }
         } 
      }
   }
   return EXIT_SUCCESS;
}
