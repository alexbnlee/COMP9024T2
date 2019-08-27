Graph freeGraph(Graph g) {
   if (g != NULL) {
       int i;
       for (i = 0; i < g->nV; i++) {
           free(g->edges[i]);  // free the mallocs for each row ...
       }
       free(g->edges);         // now the malloc for the edges array ...
       free(g);                // now the malloc for the graph rep
   }
   return g;
}
