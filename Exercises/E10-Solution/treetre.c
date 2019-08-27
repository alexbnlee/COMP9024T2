// basic.c: insert nodes into a BST, print the tree and free all nodes
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Tree;
struct node {
   int data;
   Tree left;
   Tree right;
};

Tree insertTree (Tree, int);
Tree createTree (int);
void printTree  (Tree, int);
void freeTree   (Tree);

int  sumTree    (Tree);
Tree revTree    (Tree);

int main(int argc, char **argv){
   Tree t = NULL;

   int i;
   for (i=1; i<argc; i++) {
       int num;
       if (sscanf(argv[i], "%d", &num) != 1) {
          fprintf(stderr, "Invalid argument found\n");
          exit(EXIT_FAILURE);
       }
       t = insertTree (t, num);
   }
   printTree (t, 0);

   if (t != NULL) {
       printf("Sum = %d\n", sumTree(t));
       printf("Tree in reverse\n");
   }
   Tree revt = revTree(t);
   printTree (revt, 0);
   if (t != NULL) {
       printf("Sum = %d\n", sumTree(revt));
   }
   freeTree(t);
   freeTree(revt);
   return EXIT_SUCCESS;
}

Tree insertTree(Tree t, int v) {
   if (t == NULL) {
      t = createTree(v);
   }
   else {
      if (v < t->data) {
        t->left = insertTree (t->left, v);
      }
      else {
        t->right = insertTree (t->right, v);
      }
   }
   return t;
}

Tree createTree (int v) {
   Tree t = NULL;

   t = malloc (sizeof(struct node));
   if (t == NULL) {
      fprintf(stderr, "Memory is exhausted: exiting\n");
      exit(1);
   }
   t->data = v;
   t->left = NULL;
   t->right = NULL;
   return t;
}

void printTree(Tree t, int depth) { // extra depth parameter
    if (t != NULL) {
        depth++;
        printTree (t->left, depth);
           for (int i=1; i<depth; i++){ // 'depth'*whitespace
              putchar('\t');
           }
           printf ("%d\n", t->data); // node to print
        printTree (t->right, depth);
    }
    return;
}

void freeTree(Tree t) { // free in postfix fashion
   if (t != NULL) {
      freeTree(t->left);
      freeTree(t->right);
      free(t);
   }
   return;
}

int sumTree(Tree t) { // sum all the nodes in the tree t
   int sum = 0;
   if (t != NULL) {
      sum = t->data + sumTree(t->left) + sumTree(t->right);
   }  
   return sum;
}

Tree revTree(Tree t) { // copy and reverse in one
   Tree copy = NULL;
   if (t != NULL) {
      copy = malloc(sizeof(struct node));
      if (copy == NULL) {
         fprintf(stderr, "Exhausted memory\n");
         exit(1);
      }
      copy->data = t->data;
      copy->right = revTree(t->left);
      copy->left  = revTree(t->right);
   }
   return copy;
}
