// sumTree.c: sum the nodes in a BST
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Tree;
struct node {
   int data;
   Tree left;
   Tree right;
};

Tree createTree(int);       // create a BST with root 'v'
Tree insertTree(Tree, int); // insert a node 'v' into a BST
void printTree(Tree, int);  // print a BST with indentation
void freeTree(Tree);        // free memory
int  sumTree(Tree);         // sum the nodes in a tree

int main(void) {
   Tree t = NULL;
   t = createTree (t, 18); 
   t = insertTree (t, 8);
   t = insertTree (t, 26);
   t = insertTree (t, 5);
   t = insertTree (t, 14);
   t = insertTree (t, 23);
   t = insertTree (t, 20);
   t = insertTree (t, 1);
   t = insertTree (t, 3);
   printTree (t, 0);
   printf("Sum = %d\n", sumTree(t));
   freeTree(t);
   return EXIT_SUCCESS;
}

int sumTree(Tree t) { // sum all the nodes in the tree t
   int sum = 0;
   if (t != NULL) {
      sum = t->data + sumTree(t->left) + sumTree(t->right);
   }  
   return sum;
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

void printTree(Tree t, int depth) {
    if (t != NULL) {
        printTree (t->left, ++depth);
        int i;
        for (i=1; i<depth; i++){
            putchar('\t');
        }
        printf ("%d\n", t->data);
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
