#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  //TESTING----------------------------------------
  struct matrix *edges;

  edges = new_matrix(4, 4);

  printf("matrix1:\n");
  print_matrix(edges);

  ident(edges);
  printf("matrix1 identity matrix:\n");
  print_matrix(edges);

  scalar_mult(2,edges);
  printf("matrix1 scalar multiplication by 2\n");
  print_matrix(edges);
  
  struct matrix *edges2;
  
  edges2 = new_matrix(4,2);
  
  printf("matrix2:\n");
  add_edge(edges2,1,2,3,4,5,6);
  add_point(edges2,7,7,7);
  print_matrix(edges2);

  matrix_mult(edges,edges2);
  printf("matrix1 * matrix2\n");
  print_matrix(edges2);
  //----------------------------------------------

  //REAL IMAGE

  c.red = MAX_COLOR;
  c.blue = MAX_COLOR;
  c.green = 0;
  
  struct matrix *mx;
  int x0,x1,y0,y1;
  x0 = x1 = y0 = y1 = 250;
  
  while (x0 > 0){
    mx = new_matrix(4,2);
    x0 -= 24;
    x1 += 24;
    y0 += 7;
    y1 -= 7;
    
    add_edge(mx,x0,y0,0,250,y1,0);
    add_edge(mx,250,y0,0,x1,y1,0);
    add_edge(mx,250,y0,0,x1,y0,0);
    add_edge(mx,x0,y1,0,250,y1,0);
    
    /*add_edge(mx,x0,y0,0,250,y1,0);
    add_edge(mx,250,y0,0,x1,y1,0);
    add_edge(mx,x0,y0,0,250,y0,0);
    add_edge(mx,250,y1,0,x1,y1,0);*/
    
    c.red -= 20;
    draw_lines(mx,s,c);
  }

  display(s);
  save_extension(s, "matrix.png");

  free_matrix( edges );
}  
