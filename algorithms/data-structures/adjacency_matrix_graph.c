#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

//graph struct
struct graph_{
  int size;
  int** matrix;
};

//create a graph of size n
GRAPH* graph_create(int n){
  GRAPH* g = malloc(sizeof(GRAPH));

  g->size = n;
  g->matrix = (int**)malloc(sizeof(int*)*n);

  for(int i = 0; i<n; i++){
    g->matrix[i] = (int*)calloc(n,sizeof(int));
  }

  return g;
}

//destroys the graph g that must be passed as reference
void graph_destroy(GRAPH** g){
  if(*g != NULL){
    for(int i = 0; i < (*g)->size; i++){
      free((*g)->matrix[i]);
    }
    free((*g)->matrix);
    free(*g);
    (*g) = NULL;
  }
  return;
}

//add an edge from 'a' to 'b' in graph 'g'
bool graph_add_edge(int a, int b, GRAPH* g){
  if(a >= 0 && a < g->size && b >= 0 && b < g->size){
    g->matrix[a][b] = 1;
    return TRUE;
  }
  return FALSE;
}

//remove the edge from 'a' to 'b' in graph 'g'
bool graph_rmv_edge(int a, int b, GRAPH* g){
  if(a >= 0 && a < g->size && b >= 0 && b < g->size){
    g->matrix[a][b] = 0;
    return TRUE;
  }
  return FALSE;
}

//print 'g's adjacency matrix
void graph_print(GRAPH* g){
  for(int i = 0; i<g->size; i++){
    for(int j = 0; j<g->size; j++){
      printf("%d ", g->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
