 /*
  able.c
  A straightforward solution is to use 4 nested loops and a conditional statement to
  filter out all strings with duplicate characters.
  The following program includes a counter to check how many strings have been generated.
  There are 4! = 24 permutations of "able".
  */
 #include <stdio.h>
 #include <stdlib.h>

 #define LEN 4

 int main(void) {
    char able[] = { 'a','b','e','l' };

    int count = 0;
    for (int i=0; i<LEN; i++) {
       for (int j=0; j<LEN; j++) {
          for (int k=0; k<LEN; k++) {
             for (int l=0; l<LEN; l++) {
                if (i!=j && i!=k && i!=l && j!=k && j!=l && k!=l) {
                   printf("%c%c%c%c\n", able[i], able[j], able[k], able[l]);
                   count++;
                }
             }
          }
       }
    }
    printf("%d\n", count);
    return EXIT_SUCCESS;
 }
