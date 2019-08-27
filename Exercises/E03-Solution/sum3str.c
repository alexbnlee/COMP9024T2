// sum3str.c: sum 3 hardcoded strings
 #include <stdio.h>
 #include <stdlib.h>

 int main() {
    char *r = "1";
    char *s = "23";
    char *t = "456";
    int i, j, k;
    if ((sscanf(r, "%d", &i) == 1) &&
        (sscanf(s, "%d", &j) == 1) &&
        (sscanf(t, "%d", &k) == 1)) {
       printf("%d\n", i+j+k);
   }
   return EXIT_SUCCESS;
 }
