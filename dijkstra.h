//2330,2320


#ifndef DISKTRA
#define DISKTRA
#include <stdbool.h>
#define V 9

int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[]);
void dijkstra(int graph[V][V], int src);


#endif