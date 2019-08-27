// unReachable.c: read a graph and list all the unreachable vertices, if any
#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "IOmem.h"

#define STARTVERTEX 0

void showUnreach(Graph, int, int);

int main (void) {
    int numV;
    if ((numV = readNumV()) > 0) {
        Graph g = newGraph(numV);
        if (readBuildGraph(g)) {
           showGraph(g);
           showUnreach(g, numV, STARTVERTEX);
        }
        g = freeGraph(g);
        g = NULL;
    }
    else {
        printf("Error in reading #number\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void showUnreach(Graph g, int numV, Vertex startv) {
   int *outside = mallocArray(numV);   // all set to UNVISITEDs
   outside[startv] = 0;                // 0 means inside
   int changing = 1;
   while (changing) {                  // as long as we find new adj v's
      changing = 0;
      for (Vertex v = 0; v < numV; v++) {
         if (!outside[v]) {            // check every reachable vertex
            for (Vertex w = 0; w < numV; w++) {
               if (isEdge(newEdge(v,w), g) && outside[w] == UNVISITED) { // new?
                  outside[w] = 0;      // it's now inside
                  changing = 1;        // indicate there's a change
               }
            }
         }
      }
   }
   printf("Unreachable vertices = ");
   int any = 0;                        // assume none outside
   for (Vertex v = 0; v < numV; v++) {
      if (outside[v] == UNVISITED) {   // if any vertex is unreachable ...
         printf("%d ", v);             // print the vertex
         any = 1;                      // is at least 1
      }
   }
   if (!any) {                         // if none outside
      printf("none");
   }
   putchar('\n');
   return;
}
