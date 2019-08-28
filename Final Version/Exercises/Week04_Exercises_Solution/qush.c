// qush.c for the ADT quackLL.c

void qush(int data, Quack que) { // adds data to the end of linked list
   Quack newnode;
   Quack endnode;
   if (que == NULL) {
      fprintf(stderr, "qush: quack not initialised\n");
   }
   else {
      newnode = malloc(sizeof(struct _node));
      if (newnode == NULL) {
         fprintf(stderr, "qush: no memory, aborting\n");
         exit(1);
      }
      newnode->data = data;
      newnode->next = NULL;           // = bottom of quack = end of linked list
      endnode = que;
      while (endnode->next != NULL) { // go to the end of the list
         endnode = endnode->next;
      }
      endnode->next = newnode;        // newnode is the new end of list
   }
   return;
}
