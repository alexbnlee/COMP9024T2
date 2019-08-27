/* array2heap.c convert a hard-coded array into a heap, in-situ
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

int main(void){
   int heap[] = {-999,1,2,3,4,5,6,7};// a hard-coded array testcase

   int in; // 'in' will step through the array, one by one
   for (in=1; in<=sizeof(heap)/sizeof(heap[0])-1; in++) {
      fixUp(heap, in);
   }
   // when finished, 'in' is the index of the final element + 1
   for (int i=0; i<in; i++) { // print everything until 'in'
      printf("%d ", heap[i]);
   }
   putchar('\n');
   return EXIT_SUCCESS;
}
