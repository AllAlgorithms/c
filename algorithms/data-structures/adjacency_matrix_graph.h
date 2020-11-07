#ifndef GRAPH_H
#define GRAPH_H
#define TRUE 1
#define FALSE 0

/*
Simple implementation of an adjacency matrix graph
*/

typedef int bool;
typedef struct graph_ GRAPH;

//create a graph of size 'n'
GRAPH* graph_create(int n);
//destroys the graph 'g' that must be passed as reference
void graph_destroy(GRAPH** g);
//add an edge from 'a' to 'b' in graph 'g'
bool graph_add_edge(int a, int b, GRAPH* g);
//remove the edge from 'a' to 'b' in graph 'g'
bool graph_rmv_edge(int a, int b, GRAPH* g);
//print 'g's adjacency matrix
void graph_print(GRAPH* g);

#endif
