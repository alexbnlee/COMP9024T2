/*
 * matcher.c: check whether stdin contains balanced (), [] and {}
 *
 * The program reports only if input is NOT balanced, otherwise silent.
 *
 * This matcher is not smart enough to be used in a compiler.
 * For example the text
 *      if (c == ')') printf("the char is a closing parenthesis\n");
 * would fail the matcher program but is syntactically correct.
 */
#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

#define OPENA '('
#define CLOSA ')'
#define OPENB '{'
#define CLOSB '}'
#define OPENC '['
#define CLOSC ']'
 
int main() {
   Quack st;
   char bracket;
 
   st = createQuack();
   int mismatch = 0;
   while ((bracket = getchar()) != EOF && !mismatch) { // the whole file is read
     if (bracket == OPENA || bracket == OPENB || bracket == OPENC) {
        push(bracket, st); // type correctness requires the char to be cast to an int
     }
     else if (bracket == CLOSA || bracket == CLOSB || bracket == CLOSC) {
        if (isEmptyQuack(st)) {
           mismatch = 1; // opening bracket missing
        }
        else {
           char closing = pop(st); // should cast the int to char after popping
           if (!((closing == OPENA && bracket == CLOSA) ||
                 (closing == OPENB && bracket == CLOSB) ||
                 (closing == OPENC && bracket == CLOSC))) {
               mismatch = 1;    // opening and closing brackets are different
           }
        }
     }
  }
  if (!isEmptyQuack(st) || mismatch) {
     printf ("mismatch detected\n");
  }
  return EXIT_SUCCESS;
}
