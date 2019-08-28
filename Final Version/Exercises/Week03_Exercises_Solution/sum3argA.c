// sum3argA.c: sum 3 arguments from the command line using sscanf
 #include <stdio.h>
 #include <stdlib.h>

 int main(int argc, char *argv[]) {
    int i, j, k;
    if ((argc == 4) &&
       (sscanf(argv[1], "%d", &i) == 1) &&
       (sscanf(argv[2], "%d", &j) == 1) &&
       (sscanf(argv[3], "%d", &k) == 1)) {
       printf("%d\n", i+j+k);
    }
    return EXIT_SUCCESS;
 }
// If any of the sscanf's fails to read an integer, then the program does nothing of course, as required.
// This happens if any of the command-line arguments is non-integer, such as in './sum3argA 1 z 3'
