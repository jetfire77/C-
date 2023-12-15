#include<bits/stdc++.h>
using namespace std;



struct node {
	int u;
	int v;
	int wt;
	node(int first , int second , int weight)
	{
		u= first;
		v= second;
		wt = weight;

	}
};

int main()
{

// INPUT
// 5 6
// 0 1 3
// 0 2 5
// 1 4 1
// 1 3 3
// 2 3 1
// 3 4 2
// 0


	int N, m;
	cin>>N>>m;

	vector<node> edges;
	for(int i = 0 ; i<m ; i++)
	{
		int u , v, wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u, v, wt));
	}

	int src;
	cin>> src;

	int inf = 100000000;
	vector<int> dist(N, inf);

	dist[src] = 0;

	for(int i  = 1 ; i<=N-1 ;i++)
	{
		for(auto it:edges)
		{
			if(dist[it.u] + it.wt< dist[it.v])
			{
				dist[it.v] = dist[it.u]+ it.wt;
			}
		}
	}

		int fl =0;
		for(auto it:edges)
		{
			if(dist[it.u] + it.wt < dist[it.v])
			{
				cout<<"negative cycle";
				fl = 1;
				break;
			}
		}

		if(!fl)
		{
			for(int i=0 ; i< N ;i++)
			{
				cout<<i<<" "<<dist[i]<<endl;
			}
		}

	return 0;
}














