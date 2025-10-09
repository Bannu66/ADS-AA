// Aim: Implement BFT and DFT for given graph, when graph is represented by Adjacency Matrix

#include <stdio.h> #include <stdlib.h>

#define MAX 100

void BFT(int graph[MAX][MAX], int n, int start) 
{ 
int queue[MAX], front = -1, rear = -1,i,j;
int visited[MAX] = {0};
printf("Breadth-First Traversal starting from vertex %d: ", start);
queue[++rear] = start;
visited[start] = 1;
while (front != rear) 
{
start = queue[++front];
printf("%d ", start);
for (i = 0; i < n; i++) 
{
if (graph[start][i] == 1 && !visited[i]) 
{ 
queue[++rear] = i;
visited[i] = 1;
}
}
}
printf("\n");
}

void DFTUtil(int graph[MAX][MAX], int n, int start, int visited[MAX])
{
int i;
visited[start] = 1;
printf("%d ", start); for (i=0; i < n; i++) {
if (graph[start][i] == 1 && !visited[i]) 
{ 
DFTUtil(graph, n, i, visited);
}
}
}

void DFT(int graph[MAX][MAX], int n, int start) 
{ 
int visited[MAX] = {0};
printf("Depth-First Traversal starting from vertex %d: ", start);
 
DFTUtil(graph, n, start, visited);
printf("\n");
}

int main() {
int graph[MAX][MAX]; int n, choice, start,i,j; char ch;
printf("Enter the number of vertices in the graph: "); 
scanf("%d", &n);
printf("Enter the adjacency matrix of the graph:\n");
for (i=0; i < n; i++)
 {
for (j = 0; j < n; j++) 
{ 
scanf("%d", &graph[i][j]);
}
}

do
{
printf("Enter the starting vertex: "); 
scanf("%d", &start);

printf("Choose the traversal method:\n");
printf("1. Breadth-First Traversal (BFT)\n"); 
printf("2. Depth-First Traversal (DFT)\n"); 
scanf("%d", &choice);
switch (choice) 
{ 
case 1: BFT(graph, n, start); 
	break;
case 2:DFT(graph, n, start); 
	break;
default: printf("Invalid choice!\n");
	 break;
}
printf("Do you want to continue :y/n \n");
ch=getch();
} while (ch=='y');

return 0;
}
