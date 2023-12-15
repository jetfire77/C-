#include<bits/stdc++.h>



using namespace std;
#define v 9
int findmin(int dis[] , bool ss[])
{
	int min = INT_MAX;
	int minind ;

	for(int i = 0 ; i< v ;i++)
	{
		if(ss[i]== false && dis[i]<= min)
		{
			min = dis[i];
			minind = i;
		}
	}

	return minind;
}
void dijkstra( int graph[v][v] , int src)
{

	int dis[v];
	bool ss[v];

	for(int i = 0 ; i< v ;i++)
	{
		dis[i]=INT_MAX;
		ss[i]= false;
	}

	dis[src]= 0;

	for(int c = 0 ; c<v-1 ; c++)
	{

      int u = findmin(dis , ss);
      cout<<"u "<<u<<"\n";
      cout<<"dis "<<dis[u]<<"\n ";

      ss[u]= true;
     
      for(int i = 0 ; i< v ;i++)
	{
		cout<<dis[i]<<" ";
		
	}
	cout<<"\n";

      for(int i = 0 ; i< v ;i++)
      {
      	if(!ss[i] && graph[u][i] && dis[u]!=INT_MAX   && dis[u] + graph[u][i] < dis[i])
      		{dis[i]=dis[u] + graph[u][i];
      		 cout<<"dis[v] "<<dis[i]<<"\n ";
      			}
      }

	}

	for(int i = 0 ; i < v ; i++)
		cout<<"shortest distance from "<<0<<" to"<<i<<" is"<<dis[i]<<"\n";


}




int main()
{


 int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

 				dijkstra(graph , 0);



 	return 0 ;


}


