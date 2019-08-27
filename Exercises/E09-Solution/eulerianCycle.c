/* All vertices in an Eulerian graph have even degree.

   eulerianCycle.c: check an input graph is Eulerian by countig the degree
                    of every vertex.
                    If all vertices have even degree generate an Eulerian cycle,
                    otherwise report that the graph is not Eulerian.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Quack.h"
#include "IOmem.h"

#define STARTVERTEX 0          // start the depth-first search at this vertex

int isEulerian(Graph, int);
void findEulerCycle(Graph, int, Vertex);
Vertex getAdjacent(Graph, int, Vertex);

int main (void) { 
    int numV;
    if ((numV = readNumV()) > 0) {
        Graph g = newGraph(numV);
        if (readBuildGraph(g)) {
           showGraph(g);
           if (isEulerian(g, numV)) {
              findEulerCycle(g, numV, STARTVERTEX);
           }
           else {
              printf("Not Eulerian\n");
           }
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

int isEulerian(Graph g, int numV) {
   // count the degrees by checking the number of edges at each vertex
   int count = 0;
   for (Vertex v = 0; v < numV && count%2 == 0; v++) { // stop if count odd
     count = 0;
     for (Vertex w = 0; w < numV; w++) {
        if (isEdge(newEdge(v, w), g)) {
           count++; // count how many edges are attached to v
        }
     }
   }
   return count%2 == 0;
}

// THE LECTURE NOTES (GRAPH SEARCH APPLIATIONS) CONTAINS A VERSION
// OF FINDEULERCYCLE() THAT DOES NOT HANDLE DISCONNECTED GRAPHS.
// THE VERSION OF FINDEULERCYCLE() BELOW DOES.
// IT IS LEFT AS PART OF THE WEEK9 EXERCISES TO ADD THIS TO THE
// LECTURE VERSION.

void findEulerCycle(Graph g, int numV, Vertex startv) {
   // assumes the graph is Eulerian
   Quack s = createQuack();
   push(startv, s);

   int allVis = 0;
   while (!allVis) {
      printf("Eulerian cycle: ");
      while (!isEmptyQuack(s)) {
         Vertex v = pop(s); // pop and then ...
         push(v, s);        // ... push back on, so no change
         Vertex w = getAdjacent(g, numV, v); // get largest adj. v
         if (w >= 0) {      // if true, there is an adj. vertex
            push(w, s);     // push this vertex onto stack
            removeEdge(newEdge(v, w), g); // remove edge to vertex
         }
         else {             // top v on stack has no adj. vertices
            w = pop(s);
            printf("%d ", w);
         }
      } // stack is empty but are we finished?
      putchar('\n');
      allVis = 1;
      for (Vertex v = 0; v < numV && allVis; v++) {
         for (Vertex w = 0; w < numV && allVis; w++) {
            if (isEdge(newEdge(v, w), g)) { // any remaining edges?
               printf("Graph is disconnected\n"); // debug
               allVis = 0;    // found an unvisited vertex
               push(v, s);    // push vertex onto stack
            }
         }
      }
   }
}

Vertex getAdjacent(Graph g, int numV, Vertex v) {
   // returns the largest adjacent vertex if it exists, else -1
   Vertex retv = -1; // the adjacent vertex
   for (Vertex w = numV - 1; w >= 0 && retv == -1; w--) {
      if (isEdge(newEdge(v, w), g)) {
         retv = w;
      }
   }
   return retv;
}
