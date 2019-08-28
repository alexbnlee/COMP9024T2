/* euclidit.c
Euclid's algorithm to compute the greatest common divisor (GCD) of two integers
x and y is expressed recursively as:

    if (y==0)  then GCD(x,0) = x  else GCD(x,y) = GCD(y, x mod y)

Write a function, euclidit(), which implements an iterative version of this algorithm,
but you are restricted in the following way:
 - you are not allowed to use division (/), multiplication (*) and remainder (\%) operators
 - you are not allowed to use more than one loop
 - you are not allowed to call another function

Use the main function provided to test the function.
Simply change the #defines to carry out further testing.
 */

#define NUM1 64
#define NUM2 78

#include <stdio.h>
#include <stdlib.h>

int euclidit(int x, int y) {
    while (x != y) {
       if (x > y) { x = x-y; }  // violates style guide, but much more readable here
       else       { y = y-x; }
       printf("x = %d, y = %d\n", x, y); // debug
    }
    return x;
}

int main(void) {
    printf("The GCD of %d and %d is %d\n", NUM1, NUM2, euclidit(NUM1, NUM2));
    return EXIT_SUCCESS;
}
