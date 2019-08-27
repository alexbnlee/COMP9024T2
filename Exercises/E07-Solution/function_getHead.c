int getHead(List marker) {         // get & delete head node
   int retval = 0;
   if (marker == NULL) {
       fprintf (stderr, "getTail: no linked list found\n");
   }
   else if (marker->next == NULL) { // empty list
       fprintf (stderr, "getHead: list empty, return 0\n");
   }
   else {
       List p = marker->next;      // p points to head node
       marker->next = p->next;     // head is now node after p
       retval = p->data;           // p's data is saved
       free(p);                    // we're finished with p
   }
   return retval;
}
