#include<bits/stdc++.h>

using namespace std;




int partition(int arr[] , int s , int e)
{      
        int x = arr[e];
   int i = s-1;
   int j = s;
   
   for(int j = s ; j<=e-1; j++)
   {
        
       if(arr[j] < x)
       {
         i = i+1;
         swap(arr[i], arr[j]);
        

       }

      
   }

   swap(arr[i+1] , arr[e]);
   return i+1;

}


void quicksort(int arr[] , int s , int e )
{

   if(s<e)
   {
       int q = partition(arr, s, e);
       quicksort(arr , s, q-1  );
       quicksort(arr, q+1, e  );

   }

}



int main()
{
 


  int arr [] = {4,1,3,9,7};

int n = 5;

quicksort(arr,  0 , n-1 );

for(int i = 0 ; i< n ; i++)
cout<<arr[i]<<" ";



}