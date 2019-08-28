int getTail(List marker) {         // get & delete tail node
   int retval = 0;
   if (marker == NULL) {
       fprintf (stderr, "getTail: no linked list found\n");
   }
   else if (marker->next == NULL) { // empty list
       fprintf (stderr, "getTail: list empty, return 0\n");
   }
   else {
       List q = marker;            // q is prev node to p
       List p = marker->next;      // p is the head node
       while (p->next != NULL) {   // find the tail node
           q = q->next;
           p = p->next;
       }                           // p is the tail node, q is previous
       retval = p->data;           // get tail node's data
       q->next = NULL;             // q is now tail, NULL terminate it
       free(p);                    // we're finished with p
   }
   return retval;
}
