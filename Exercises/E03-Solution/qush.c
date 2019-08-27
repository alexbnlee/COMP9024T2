/*
 * qush.c
 * This operation is analogous to a 'push' operation for a stack,
 * but turns the data structure into a queue.
 * A 'qush':
 *   - shifts every element up in the array, and then
 *   - places the new data at the bottom of the array
 */
void qush(int data, Quack que) {
   if (que == NULL) {
      fprintf(stderr, "qush: quack not initialised\n");
      return;
   }
   if (que->top == HEIGHT-1) {
      fprintf(stderr, "qush: quack overflow\n");
      return;
   }
   ++que->top;                        // next available spot
   int i;
   for (i=que->top; i>=1; i--) {
      que->array[i] = que->array[i-1];// move each element up 1
   }
   que->array[0] = data;              // place new data at the bottom
   return;
}
