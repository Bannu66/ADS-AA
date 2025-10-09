// Aim: Implement BFT and DFT for given graph, when graph is represented by Adjacency Lists

#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct node
{
	int data;
	struct node *next;
};
void readgraph(struct node *ad[]);
void printgraph(struct node *ad[]);
void bfs(struct node *ad[],int start,int visited[]);
void dfs(struct node *ad[],int start,int visited[]);
int main()
{
	int i,j,k,ch,start,visited[40];
	struct node *adj[50];
	printf("Enter the total numbe of vertex :");
	scanf("%d",&no_vertices);

	for(i=0;i<no_vertices;i++)
	{
		adj[i] = NULL;
	}
	readgraph(adj);

	do{
		printf("\n1. Enter 1 for BFS\n");
		printf("\n2.Enter 2 for DFS\n");
		printf("\n3.Enter 3 to Print the adjacency list\n");
		printf("\n4.Enter 4 to Exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("Enter the vertex from which do you wanted to start :");
				scanf("%d",&start);
				for( k=0;k<no_vertices;k++)
					visited[k]=0;
				bfs(adj,start,visited); break;

			case 2:
				printf("Enter the vertex from which do you wanted to start :");
				scanf("%d",&start);
				for(k=0;k<no_vertices;k++)
					visited[k]=0;

				printf("DFS : ");
				dfs(adj,start,visited); 
				break;

			case 3: printgraph(adj);break;

			case 4: break;
		}
	}while(ch!= 4);
	return 0;
}
void readgraph(struct node *ad[])
{
	struct node *newnode;
	int i,j,k,data;

	for(i=0;i<no_vertices;i++)
	{
		struct node *last =NULL;
		printf("\nEnter the Number of neighbours of %d  :",i);
		scanf("%d",&k);

		for(j=0;j<k;j++)
		{
			printf("Enter the value of %d neighbour of %d : ",j,i);
			scanf("%d",&data);

			newnode = (struct node*)malloc(sizeof(struct node*));
			newnode->data = data;
			newnode->next = NULL;
			if(ad[i]==NULL)
			{
				ad[i] = newnode;
			}
			else
				last->next = newnode;

			last = newnode;
		}
	}
}
void printgraph(struct node *ad[])
{
	struct node *ptr  = NULL;
	int i,j;
	for(i=0;i<no_vertices;i++)
	{
		ptr = ad[i];
		printf("\n The neighbour of %d are :",i);
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
}
void bfs(struct node *ad[],int start,int visited[])
{
	int queue[50],front=-1,rear=-1;
	struct node *ptr;


	printf("BFS : ");
	queue[++rear] = start;
	visited[start]=1;
	front++;
	while(front<=rear)
	{
		printf("%d\t",queue[front]);

		ptr =  ad[queue[front++]];
		while(ptr != NULL)
		{
			if(visited[ptr->data]!=1)
			{
				queue[++rear] = ptr->data;
				visited[ptr->data] =1;
			}
			ptr = ptr->next;
		}

	}

}
void dfs(struct node *ad[],int start, int visited[])
{
	struct node *ptr;
	visited[start] = 1;
	printf("%d\t",start);

	ptr = ad[start];
	while(ptr!=NULL)
	{
		if(visited[ptr->data]==0)
			dfs(ad,ptr->data,visited);
		ptr = ptr->next;
	}
}
