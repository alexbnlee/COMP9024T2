/* args2heap
   reads command-line arguments, converts them to integers, inserts them into a heap, and prints the heap
   - does not use arrays, except for argv[]
 */

#include <stdio.h>
#include <stdlib.h>

// fix up the heap for the 'new' element at index child
void fixUp(int *heap, int child) {
   while (child>1 && *(heap+child/2) < *(heap+child)) {
      int swap = *(heap+child);         // if parent < child, do a swap
      *(heap+child) = *(heap+child/2);
      *(heap+child/2) = swap;
      child = child/2;                // become the parent
   }
}

int main(int argc, char *argv[]) {
   int error = 0;
   if (argc >= 2) {
       int *heap = malloc((argc+1) * sizeof(int)); // 1 extra to store null later on
       if (heap == NULL) {
           fprintf(stderr, "malloc error\n");
           return EXIT_FAILURE;
       }
       int *loc = heap; // loc steps through the mallocd memory
       *loc++ = -999;   // put -999 at index location 0, get ready for next loc
       for (int in = 1; in < argc && !error; in++) { // 'in' is a sort-of counter
           if (sscanf(argv[in], "%d", loc) == 1) { // read an arg into loc
               fixUp(heap, in);  // 'in' is the 'index' of the new loc
               loc++; // get ready for the next loc
           }
           else {
               error = 1;
           }
       }
       *loc = '\0'; // terminate the 'array'
       if (!error) {
           loc = heap;  // start at the start again
           while (*loc) { // print everything
              printf("%d ", *loc++);
           }
           putchar('\n');
       }
       free(heap);
       heap = NULL;
   }
   if (argc == 1 || error ) {
       printf("Usage: %s integers ...\n", argv[0]);
       return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}
