#include<bits/stdc++.h>

using namespace std;


void merge( vector<int> &a , int s, int m , int e)
{
   

   int n1 = m-s+1;
   int n2 = e-m;

   vector<int> l(n1);
   vector<int> r(n2);

   for(int i = 0 ; i<n1 ; i++)
   {
    l[i] = a[s+i] ;

   }


   for(int i = 0 ; i<n2; i++)
   {
    r[i]= a[m+i+1];


    
   }

   // l[n1] = INT_MAX;

   // r[n2] = INT_MAX;


   int i = 0 , j = 0 , k = s;

   while( i < n1 && j <n2)
   {

    if(l[i] <= r[j])
        {a[k] = l[i];
            k++;
         i++;
         }
    else
       { a[k] = r[j];
        k++; 
          j++;
       }
   }

   while( i<n1)
   {
    a[k] = l[i];
    k++; i++;
   } 
    

    while( j<n2)
   {
    a[k] = r[j];
    k++; j++;
   }


}

void mergesort( vector<int> &a , int s , int e )
{
   if(s<e)
   {
   int m =  (s+e)/2;

   mergesort( a, s, m);
   mergesort(a, m+1, e);
   merge(a,s,m,e);
   }
}


int main()
{
	
    

   


vector<int>  a = { 1, 4, 1, 6, 8, 5, 3, 7};


mergesort(a , 0 , a.size()-1);


for(int i = 0 ; i<8 ; i++)
   
cout<<a[i]<<" ";




}
