 /*
 collatzeFib.c
  */

 #include <stdio.h>
 #include <stdlib.h>

 #define MAX 10

 void collatz(int n) {  // named after the German mathematician who invented this problem
    while (n != 1) {
       if (n % 2 == 0) {
	  n = n / 2;
       } else {
	  n = 3*n + 1;
       }
       printf("%d ", n);
    }
    putchar('\n');
 }

 int main(void) {
    int fib[MAX] = { 1, 1 };     // initialise the first two numbers

    for (int i = 2; i < MAX; i++) {  // compute the first 10 Fibonacci numbers
       fib[i] = fib[i-1] + fib[i-2];
    }

    for (int i = 0; i < MAX; i++) {  // apply Collatz's process to each fib[] element
       printf("fib[%d] = %d: ", i+1, fib[i]);
       collatz(fib[i]);
    }
    return EXIT_SUCCESS;
 }
