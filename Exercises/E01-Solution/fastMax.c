 /*
  fastMax.c
  Find the max of 3 integers.
  Makes use of the fact that true has value 1 and false has value 0.
  */
 #include <stdio.h>
 #include <stdlib.h>

 #define NUM1 12
 #define NUM2 8
 #define NUM3 24

 int fastMax(int a, int b, int c) {
    int d = a * (a >= b) + b * (a < b);   // d is max of a and b
    return  c * (c >= d) + d * (c < d);   // return max of c and d
 }

 int main(void) {
    printf ("max of %d, %d and %d is %d\n", NUM1, NUM2, NUM3, fastMax(NUM1, NUM2, NUM3));
    return EXIT_SUCCESS;
 }
