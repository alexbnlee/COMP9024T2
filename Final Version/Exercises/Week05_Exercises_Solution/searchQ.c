/* searchQ.c
Write a program called searchQ.c that reads a string of characters on stdin, places these
characters onto a queue, and searches the queue for a particular character.

The character that you are searching for is the letter 'v', which you may hard-code
into the program:
    char v = 'v';
Before you conduct the search, you must first place all the characters in
the string onto the queue, and print its contents.
Only then can you search for the letter 'v' in the queue.
Your search algorithm cannot know what elements are on the queue.

If the letter is found in the search, the program should print ``v found'', and remove
the letter, leaving the rest of the queue unchanged.
If the search does not find the letter, then it prints ``v not found''.
At completion, the contents of the queue should again be printed.
(If there is more than one 'v', you need remove only the first.)

A Quack ADT is provided in your home directory for you to use.
You may use only the operations provided by the ADT, which are listed in the
interface Quack.h. It is important that you:
 - do not use any other data structures such as arrays or lists. Only queues are permitted.
 - do not change the Quack ADT or interface in any way

To test, you can use the same input file test.inp from the first exercise
(containing the string 9024datamanavatar).
Here is a sample execution:

prompt$ ./searchQ < test.inp
Quack: <<9, 0, 2, 4, d, a, t, a, m, a, n, a, v, a, t, a, r>>
v found
Quack: <<9, 0, 2, 4, d, a, t, a, m, a, n, a, a, t, a, r>>

Notice that the letter 'v' has been 'found' and removed from the queue.
If the file test1.inp contains the string boohoohoo,
then the search obviously does not find the letter, and the queue is unchanged.

prompt$ ./searchQ < test1.inp
Quack: <<b, o, o, h, o, o, h, o, o>>
v not found
Quack: <<b, o, o, h, o, o, h, o, o>>
 */
#include <stdio.h>
#include <stdlib.h>
#include "Quack.h"

int main() {
   Quack q = createQuack();
   char v = 'v';

   char c;
   while (scanf("%c", &c) == 1 && c != '\n') {
      qush(c, q);
   }
   showQuack(q);

   int height = heightQuack(q);
   int found = 0;
   for (int i = 1; i <= height; i++) {
      c = pop(q);
      if (v == c) {
         found = 1;
         printf("%c found\n", v);
      }
      else {
         qush(c, q);
      }
   }
   if (!found) {
      printf("%c not found\n", v);
   }
   showQuack(q);
   return EXIT_SUCCESS;
}
