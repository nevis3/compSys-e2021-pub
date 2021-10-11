#include <stdlib.h>
#include <stdio.h>

//definerer at BAD_INPUT ikke må være et 0 dimensionel array
#define BAD_INPUT 0

long sum_array_cols(long *a, int M, int N)
{
  unsigned long i, j;
  long sum = 0;

  for (j = 0; j < N; j++) {
    for (i = 0; i < M; i++) {
      sum += a[i * M + j];
      printf("%lu\n", sum);
    }
  }
  return sum;
}


//the input defines the size of the matrix not actual values to be stored
//therefore ./cols 2 2 allocates memory for a 2x2 matrix with 0's in each place
int main (int argc, char* argv[]) {
  unsigned long n,m; // Array size
  if (argc != 3) { // 2 arguments needed
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }

  int res;
  res = sscanf(argv[1],"%lu", &m);
  if (res == BAD_INPUT) {
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }

  res = sscanf(argv[1],"%lu", &n);
  if (res == BAD_INPUT) {
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }

  // Give me some memory with the size of the array
  long* input = (long*) malloc(m * n * sizeof(long));
  // Note, I do not care about the input

  //adding values to the matrix, can be removed, resulting in 0's
  int i;
  for (i = 0; i < m*n; i++)
  {
    input[i] = i;
  }

  // use volatile to prevent compiler from optimizing this away!
  volatile long l = sum_array_cols(input, m, n);

  printf("Sum is: %ld\n", l);

  // Give the memory back
  free(input);

  return EXIT_SUCCESS;
}
