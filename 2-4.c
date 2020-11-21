#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_LENGTH 17
#define B_LENGTH 17


void print_int_array(int *array) {
  int i;
  printf("(");
  for(i = 0; i < A_LENGTH; ++i){
    printf("%d", array[i]);
    if (i != A_LENGTH - 1) {
      printf(", ");
    } else {
      printf(")");
    }
  }
  printf("\n");
}

int is_zero(int *array) {
  int i;
  for(i = 0; i < A_LENGTH; i++){
    if(array[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int exclusive_or(int x, int y) {
  return (x + y) % 2;
}

int poly_div(int *a, int *b) {
  int i = 0; int j = 0;
  for (i = 0; i < A_LENGTH - B_LENGTH + 1; i++) {
    if (a[i] == 1) {
      for(j = 0; j < B_LENGTH; j++) {
	a[i + j] = exclusive_or(a[i + j], b[j]);
      }
    }
  }
}


int main(void) {
  int g[B_LENGTH] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  int I[A_LENGTH] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

  poly_div(I, g);

  if (is_zero(I) == 1) {
    printf("OK!");
  } else {
    printf("not OK\n");
    print_int_array(I);
  }

  return 0;
}
