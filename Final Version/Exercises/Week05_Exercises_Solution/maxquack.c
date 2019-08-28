/* maxquack.c:
Write a client program that moves the maximum element in a stack to the top of stack
using only the operations of a quack ADT (that is provided).

To initialise the stack, your program should read integer data from stdin and push all
this data onto the stack in the input order.
The input data is terminated by a new-line, and you may assume that the data is
well-formed (there are only integers and a new-line character).
You should find the quack ADT in your home directory.

Important is the following:
 - the only data structures that you may use are Quacks (as defined by the ADT)
 - your program should not record the maximum element while reading the input data
 - your program should not know anything about the data in the stack after initialisation
 - the client of course is not allowed to malloc

For example, if the file data.inp contains the integers 2 12 5 10 3
and assuming the executable is called a.out,
then executing the program would generate the following output:

prompt$ ./a.out < data.inp
Quack: <<3, 10, 5, 12, 2>>
Quack: <<12, 3, 5, 10, 2>>

where:
 - the first line of output shows the initial stack after the data file has been
   read (note the top of stack is shown on the left), and
 - the second line shows the resulting stack with the maximum element '12', which
   was low in the stack, now at the top
Note as well that the order of the other data in the stack may be affected by the
process of moving the maximum element to the top.

I repeat and emphasise that your program may use only Quack data structures and
operations of the quack ADT.
All other data structures, such as arrays and linked lists are not allowed.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Quack.h"

#define MAX 10

int main(void) {
   Quack s = NULL;
   Quack t = NULL;
   s = createQuack();
   t = createQuack();

   int num;
   while (scanf("%d", &num) == 1) {
      push (num,s);
   }
   showQuack(s);

   int max = pop(s);
   while (!isEmptyQuack(s)) {
      int m = pop(s);
      if (m>max) { push(max, t); max = m; }
          else { push(m, t); }
   }
   while (!isEmptyQuack(t)) {
      push(pop(t), s);
   }
   push(max, s);

   showQuack(s);
   return EXIT_SUCCESS;
}
    
