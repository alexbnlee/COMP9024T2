int isEdge(Graph g, Edge e) { // return 1 if edge found, otherwise 0
   int found = 0;
   if (g != NULL && validV(g, e.v) && validV(g, e.w)) {
      found = (g->edges[e.v][e.w] == 1);
   }
   return found;
}
