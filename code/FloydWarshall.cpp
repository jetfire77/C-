#include<bits/stdc++.h>
using namespace std;
// #define v 6
# define v 4
# define INF INT_MAX




void floyd_warshall(int graph[v][v])
{
	int dist[v][v];

	for(int i = 0 ; i< v ; i++)
		for(int j=0;j<v;j++)
			dist[i][j] = graph[i][j];


	for(int k = 0 ; k< v ; k++)
	{
		for(int i = 0 ; i< v ; i++)
		{
			for(int j = 0 ; j< v ; j++)
			{
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
					{continue;}
				else if(dist[i][k]+ dist[k][j] < dist[i][j])
					dist[i][j]= dist[i][k]+dist[k][j];
			}
		}
	}

	for(int i = 0 ; i< v; i++)
	{
		if(dist[i][i]<0)
		{
			cout<<"negative edge weight cycle is present \n";
			return ;
		}
	}

	for(int i=0 ; i< v ; i++)
	{
		for(int  j = 0 ; j< v ; j++)
		{   if(dist[i][j] == INF)
			cout<<"INF"<<" ";
			else
			cout<<dist[i][j]<<" ";
		}

		cout<<"\n";

	}
}

int main()
{
	// int graph[v][v] = {{0 , 1, 4, INT_MAX, INT_MAX, INT_MAX},
	// 					{INT_MAX, 0, 4, 2, 7, INT_MAX},
	// 					{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
	// 					{INT_MAX, INT_MAX, INT_MAX ,0, INT_MAX, 4},
	// 					{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
	// 					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}	};


	int graph[v][v] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

	floyd_warshall(graph);
	return 0; 
}