#include<bits/stdc++.h>

using namespace std;




 

void insertionsort(int arr[] , int n)
{

   for(int i =  1 ; i< n ; i++)
   {
    int hole  =  i;
    int val = arr[i];

    while(hole > 0 && arr[hole-1] > val)
    {
        arr[hole] = arr[hole-1];
        hole = hole-1;

    }

    arr[hole] = val;
}
}
int main ()
{
   /* int arr[] = {1,1,1,7, -1, 0};  */   

    int arr[] = {2,7,4,1,5,3};
        
        
    int length = sizeof(arr)/sizeof(arr[0]);    
        
    insertionsort(arr, length);


    for(int i = 0 ; i< length ; i++)
        cout<<arr[i]<<" ";
        
      
    return 0;    
}

