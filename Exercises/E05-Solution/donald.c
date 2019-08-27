/* donald.c
The Student data type consists of the following fields:
   - an integer id,
   - a character string name and
   - a character morf (which stands for 'm' or'f').

The following C program calls 3 functions: to create a Student record for Donald Duck,
to print the data in the record, and to cleanup, i.e. return memory to the heap before termination.

int main(void) {
   Student *s;
   s = create(1234, "Donald Duck", 'm');
   print(s);
   s = cleanup(s);
   return EXIT_SUCCESS;

Write a definition for Student and implement each of these functions,
paying attention to the following:
  - the only variables you may use are pointers
  - you are not allowed to use arrays
  - you must not change the main program
You will need to type the main function in yourself to test your functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id;
   char *name;
   char category;
} Student;

Student *create(int num, char *nam, char c) {
    Student *s = malloc (sizeof(Student));
    if (s != NULL) {
       s->name = malloc(strlen(nam)+1); // includes room for NULL
    }
    if (s==NULL || s->name == NULL) {
       fprintf(stderr, "Out of memory\n");
       exit(1);
    }
    s->id = num;
    strcpy(s->name, nam);
    s->category = c;
    return s;
}

void print(Student *s) {
   printf("%d %s %c\n", s->id, s->name, s->category);
   return;
}

Student *cleanup(Student *s) {
   free(s->name);
   free(s);
   return NULL;
}

int main(void) {
   Student *s;
   s = create(1234, "Donald Duck", 'm'); // create a record
   print(s);                             // print a record
   s = cleanup(s);                       // no leaks, no dangles
   return EXIT_SUCCESS;
}
