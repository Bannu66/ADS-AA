// (7)-AIM: Compare the performance of Single Source Shortest Paths using Greedy method when the graph is represented by adjacency matrix and adjacency lists.
// Program:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>   
#define MAX_VERTICES 100
#define INF INT_MAX
int minDistance(int dist[], int sptSet[], int V) {
int min = INF, min_index;
int v;
for (v = 0; v < V; v++) {
if (sptSet[v] == 0 && dist[v] <= min) {
min = dist[v];
min_index = v;
}
}
return min_index;
}
void dijkstraMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
int dist[MAX_VERTICES];
int sptSet[MAX_VERTICES];
int i;
int count, v;
for (i = 0; i < V; i++) {
dist[i] = INF;
sptSet[i] = 0;
}
dist[src] = 0;
for (count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet, V);
sptSet[u] = 1;
for (v = 0; v < V; v++) {
if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}
printf("Vertex\tDistance from Source (Matrix)\n");
for (i = 0; i < V; i++) {
printf("%d\t%d\n", i, dist[i]);
}
}
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;
typedef struct Graph {
int V;
Node** array;
} Graph;
Node* newNode(int dest, int weight) {
Node* new_node = (Node*)malloc(sizeof(Node));
new_node->dest = dest;
new_node->weight = weight;
new_node->next = NULL;
return new_node;
}
Graph* createGraph(int V) {
int i;
Graph* graph = (Graph*)malloc(sizeof(Graph));
graph->V = V;
graph->array = (Node**)malloc(V * sizeof(Node*));
for (i = 0; i < V; i++) {
graph->array[i] = NULL;
}
return graph;
}
void addEdge(Graph* graph, int src, int dest, int weight) {
Node* new_node = newNode(dest, weight);
new_node->next = graph->array[src];
graph->array[src] = new_node;
}
void dijkstraList(Graph* graph, int src) {
int i, count;
Node* temp;
int V = graph->V;
int dist[MAX_VERTICES];
int sptSet[MAX_VERTICES];
for (i = 0; i < V; i++) {
dist[i] = INF;
sptSet[i] = 0;
}
dist[src] = 0;
for (count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet, V);
sptSet[u] = 1;
temp = graph->array[u];
while (temp != NULL) {
int v = temp->dest;
if (!sptSet[v] && dist[u] != INF && dist[u] + temp->weight < dist[v]) {
dist[v] = dist[u] + temp->weight;
}
temp = temp->next;
}
}
printf("Vertex\tDistance from Source (List)\n");
for (i = 0; i < V; i++) {
printf("%d\t%d\n", i, dist[i]);
}
}
int main() {
int V = 5;
int i;
int graphMatrix[MAX_VERTICES][MAX_VERTICES] = {
	{0, 10, 0, 30, 100},
	{10, 0, 50, 0, 0},
	{0, 50, 0, 20, 10},
	{30, 0, 20, 0, 60},
	{100, 0, 10, 60, 0}
    };
Graph* graphList = createGraph(V);
addEdge(graphList, 0, 1, 10);
addEdge(graphList, 0, 3, 30);
addEdge(graphList, 0, 4, 100);
addEdge(graphList, 1, 0, 10);
addEdge(graphList, 1, 2, 50);
addEdge(graphList, 2, 1, 50);
addEdge(graphList, 2, 3, 20);
addEdge(graphList, 2, 4, 10);
addEdge(graphList, 3, 0, 30);
addEdge(graphList, 3, 2, 20);
addEdge(graphList, 3, 4, 60);
addEdge(graphList, 4, 0, 100);
addEdge(graphList, 4, 2, 10);
addEdge(graphList, 4, 3, 60);
printf("Dijkstra's Algorithm using Adjacency Matrix:\n");
dijkstraMatrix(graphMatrix, 0, V);
printf("\nDijkstra's Algorithm using Adjacency List:\n");
dijkstraList(graphList, 0);
for (i = 0; i < V; i++) {
Node* temp;
while (graphList->array[i]) {
temp = graphList->array[i];
graphList->array[i] = graphList->array[i]->next;
free(temp);
}
}
free(graphList->array);
free(graphList);
getch();
return 0;
}
