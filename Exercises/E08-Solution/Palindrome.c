/* Palindrome.c

a. The algorithm

   isPalindrome(word):
      Input:  array word[0..n-1] of chars
      Output: true if word palindrome, false otherwise
   
      i = 0, j = n-1
      while i<j do
         if word[i] != word[j] then
            return false
         end if
         i = i+1, j = j-1
      end while
      return true

b. Time complexity analysis:
     Number of iterations is n/2
     Time complexity of body of loop O(1)
        (body is independent of n: consisting of 2 array accesses,
         the if-condition, an addition, a subtraction, 2 assignments)
     Total time complexity is O(n/2 * 1) = O(n)

c. The C program follows.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char word[], int len) {
   int i = 0;
   int j = len-1;
   int pal = 1;
   while (i < j && pal) {
      if (word[i] != word[j]) {
	 pal = 0;
      }
      i++;
      j--;
   }
   return pal;
}

int main(int argc, char *argv[]) {
   if (argc == 2) {
      if (isPalindrome(argv[1], strlen(argv[1]))) {
	 printf("yes\n");
      }
      else {
	 printf("no\n");
      }
   }
   return EXIT_SUCCESS;
}
