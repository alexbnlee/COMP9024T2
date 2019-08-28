  /* ackermann.c
     reads 2 non-negative numerical arguments from the command line and
     computes and prints Ackermann's function for these numbers.
   */

  #include <stdio.h>
  #include <stdlib.h>

  int ackermann(int m, int n);

  int main(int argc, char *argv[]) {
    int error = 0;
    if (argc == 3) {
        int m, n;
        if (sscanf(argv[1], "%d", &m) == 1 &&
            sscanf(argv[2], "%d", &n) == 1) {
            if (m>=0 && n>=0) {
                printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
            }
            else {
                printf("Ackermanns function is not defined for negative integers\n");
            }
        }
        else {
            error = 1;
        }
    }
    if (argc != 3 || error) {
        printf("Usage: %s m n\n", argv[0]);
    }
    return EXIT_SUCCESS;
  }

  int ackermann(int m, int n) {
    if (m < 0 || n < 0) {
        return 0; // Not defined for negative arguments
    }

    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
  }

