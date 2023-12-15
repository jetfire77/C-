

#include<bits/stdc++.h>

using namespace std;





    void heapify(int arr[], int n, int i)  
    {
      int l = 2*i+1;
      int r =2*i + 2;
      
      int largest = i;
      if( l< n && arr[l]>arr[largest])
      largest = l;
      
      
      if(r < n && arr[r] > arr[largest] )
      largest =  r;
      
      if(largest != i)
     { swap(arr[i],arr[largest]);
      
      heapify(arr,n, largest);
     }
     
    }

    
    void buildHeap(int arr[], int n)  
    { 
      for( int i =  n/2-1 ; i>= 0 ; i--)
      heapify(arr ,n, i);
      
      
      
    }

    
    
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int  i = n-1 ; i>0 ;i--)
       { swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
       }
    }




int main()
{

  

int arr [] = {4,7,0,1,3};

int n = 5;

heapSort(arr,  n);

for(int i = 0 ; i< n ; i++)
cout<<arr[i]<<" ";




    


}