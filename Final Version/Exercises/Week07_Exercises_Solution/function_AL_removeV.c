// a linear search for w in v's linked list
static int removeV(Graph g, Vertex v, Vertex w) { // return 1 if found&removed
   // just removes the vertex, removeEdge() decrements g->nE
   int success = 0;

   List n = g->edges[v];  // n is the start node
   List p = NULL;         // p is previous node to n
   while (n != NULL && !success){ // linear search for w
      if (n->name == w) {
         List nn = n->next; // we've found w, we want to skip over it
         if (p == NULL) {   // if w is first node, p will be NULL
            g->edges[v] = nn;
         } else {
            p->next = nn;
         }
         free(n);
         success = 1;
      }
      p = n;
      n = n->next;
   }
   return success;
}
