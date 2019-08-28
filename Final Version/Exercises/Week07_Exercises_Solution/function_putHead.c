void putHead(int n, List marker) { // insert at the head
   if (marker == NULL) {
       fprintf (stderr, "putHead: no linked list found\n");
   }
   else {
       List new = createList();    // re-use of createList to make a node
       new->data = n;              // overwrite INT_MAX with proper data
       new->next = marker->next;   // link new node to old List head
       marker->next = new;         // new node is now List head 
   }
   return;
}
