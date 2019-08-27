/* cHeap.c
The program reads single, alphanumeric characters on the command line
and stores them in a heap. The heap is printed if it is non-empty.
Arguments that are not single && alphanumeric are ignored.

No arrays are used, except for *argv[].
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fixUp(char *heap, int child) {
    while (child>1 && *(heap+child/2) < *(heap+child)) {
       char swap = *(heap+child);    // if parent < child, do a swap
       *(heap+child) = *(heap+child/2);
       *(heap+child/2) = swap;
       child = child/2;                // become the parent
    }
    return;
}

int main(int argc, char *argv[]) {
    char *p;
    char *heap = malloc((argc + 1) * sizeof(char)); // + 1 for the null
    if (heap == NULL) {
        fprintf(stderr, "out of memory\n");
        return EXIT_FAILURE;
    }
    p = heap;    // we use p to add alphanums to the heap
    *p++ = '#';  // put in some character at location 0
    for (int i = 1; i < argc; i++) {
        if (isalnum(*argv[i]) && *(argv[i]+1) == '\0') {
            *p++ = *argv[i];
            fixUp(heap, i);
        }
    }
    *p = '\0';        // terminate the string in the heap
    if (p > heap+1) { // p must be at least heap+1 because of the #
        printf("Heap = %s\n", heap);
    }
    free(heap);
    heap = NULL;
    return EXIT_SUCCESS;
}
