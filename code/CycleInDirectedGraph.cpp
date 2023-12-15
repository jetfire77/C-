

#include<bits/stdc++.h>

using namespace std;


bool solve( vector<int> g[] , int v , int src , vector<int> &vis,  vector<int> &ord)
{

    ord[src] = 1;
    vis[src] = 1;

    for(auto x : g[src])
    {

        if(!vis[x])
        {

            bool cyc = solve(g, v, x, vis, ord);
            if(cyc)  return true;
        }

        else if(ord[x]) return true;
    }
    
    ord[src] = 0;

    return false;
}



bool func( vector<int> g[] , int v)
{
   
   vector<int>  vis(v, 0);
   vector<int> ord(v,0);

   
   for(int i = 0 ; i< v; i++)
   {
      if(!vis[i])
      {

         bool cyc = solve( g, v, i , vis , ord);
         if(cyc) return true;



      }

   }
   return false;


}


int main()
{
    

    int t;

    cin>>t;


    while(t--)
    {    
           

           int n, e;


            cin>>n>>e;


            vector<int> g[n];


            for(int i = 0 ; i < e ; i++)
            {
                int a, b;

                cin>>a>>b;

                g[a].push_back(b);
            }




            if(func( g , n))
                cout<<"YES";
            else
                cout<<"NO";



}

}