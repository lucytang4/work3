#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  printf("matrix1:\n");
  print_matrix(edges);

  ident(edges);
  printf("matrix1 identity matrix:\n");
  print_matrix(edges);

  scalar_mult(2,edges);
  printf("4x4 scalar multiplication by 2\n");
  print_matrix(edges);
  
  struct matrix *edges2;
  
  edges2 = new_matrix(4,2);
  
  printf(
  

  free_matrix( edges );
}  
