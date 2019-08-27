int isEdge(Graph g, Edge e) {
// a linear search for edge 'e': return 1 if edge found, 0 otherwise
   int found = 0;
   if (g != NULL && validV(g, e.v) && validV(g, e.w)) {
      list curr;
      for (curr = g->edges[e.v]; curr != NULL && !found; curr = curr->next) {
         if (curr->name == e.w) {
            found = 1;
         }
      }
   }
   return found;
}
