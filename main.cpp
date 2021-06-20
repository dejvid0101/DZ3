#include<iostream>
#include<climits>
using namespace std;

// this method returns a minimum distance for the
// vertex which is not included in Tset.

void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);

}
int minimumDist(int dist[], bool Tset[])
{
	int min=INT_MAX,index;

	for(int i=0;i<25;i++)
	{
		if(Tset[i]==false && dist[i]<=min)
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[25][8],int src) // adjacency matrix used is 6x6
{
	int dist[25]; // integer array to calculate minimum distance for each node.
	bool Tset[25];// boolean array to mark visted/unvisted for each node.
    int parent[25];
	// set the nodes with infinity distance
	// except for the initial node and mark
	// them unvisited.
	for(int i = 0; i<25; i++)
	{
	    parent[0] = -1;
		dist[i] = INT_MAX;
		Tset[i] = false;
	}

	dist[src] = 0;   // Source vertex distance is set to zero.

	for(int i = 0; i<25; i++)
	{
		int m=minimumDist(dist,Tset); // vertex not yet included.
		Tset[m]=true;// m with minimum distance included in Tset.
		for(int i = 0; i<25; i++)
		{
			// Updating the minimum distance for the particular node.
			if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                parent[i] = m;
				dist[i]=dist[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source\tPath"<<endl;
	for(int i = 0; i<25; i++)
	{ //Printing
		int str=i; // Ascii values for pritning A,B,C..
		cout<<str<<"\t\t\t"<<dist[i]<<"\t\t";
		printPath(parent, i);
		cout<<endl;

	}
}


int main()
{
	int graph[25][8]={
		{0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 1,1},
		{0, 0, 0, 1, 1, 1, 1,1},
		{0, 0, 0, 1, 1, 1, 1,1},
		{0, 0, 0, 0, 0, 1, 1,1},
		{0, 1, 1, 1, 1, 1, 0,0},
		{1, 1, 1, 1, 100000, 1, 1,1},
		{1, 1, 1, 1, 1, 100000, 1,1},
		{1, 1, 1, 1, 1, 1, 100000,1},
		{1, 1, 0, 0, 0, 1, 1,1},
		{0, 1, 1, 1, 1, 1, 0,0},
		{1, 1, 1, 100000, 1, 1, 1,1},
		{1, 1, 1, 1, 1, 1, 1,1},
		{1, 1, 1, 1, 1, 1, 1,100000},
		{1, 1, 0, 0, 0, 1, 1,1},
		{0, 1, 1, 1, 1, 1, 0,0},
		{1, 1, 100000, 1, 1, 1, 1,1},
		{1, 100000, 1, 1, 1, 1, 1,1},
		{100000, 1, 1, 1, 1, 1, 1,1},
		{1, 1, 0, 0, 0, 1, 1,1},
		{0, 1, 1, 1, 0, 0, 0,0},
		{1, 1, 1, 1, 0, 0, 0,1},
		{1, 1, 1, 1, 0, 0, 0,1},
		{1, 1, 1, 1, 0, 0, 0,1},
		{1, 1, 0, 0, 0, 0, 0,1}};
	Dijkstra(graph,0);
	return 0;
}
