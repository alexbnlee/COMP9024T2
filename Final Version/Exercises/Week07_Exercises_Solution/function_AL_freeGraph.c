Graph freeGraph(Graph g) {
   if (g != NULL) {
      int i;
      for (i = 0; i < g->nV; i++) {
         List node = g->edges[i]; // maybe NULL, maybe points to first node
         while (node != NULL) {
            List tmp = node;   // save the node
            node = node->next; // move onto the next node
            free(tmp);         // free the saved node
         }
      }
      free(g->edges);   // now the malloc for the edges array ...
      free(g);          // now the malloc for the graph rep
      g = NULL;
   }
   return g;
}
