#include<iostream>
using namespace std;

int partition(int A[],int low, int high )
 {
    int pivot = A[low];
    int i = low;
    int j = high;
   
    while(i<j){
        
        while(A[i]<=pivot){i++;}  
        
        while(A[j]>pivot){j--;}
        
            if(i<j){
                swap(A[i], A[j]);
            }
        }
   
   swap(A[low], A[j]);
   return j;
 }

void QuickSort(int A[],int l,int h){
    int j;
    if(l<h){
       j=partition(A,l,h);
       QuickSort(A,l,j);
       QuickSort(A,j+1,h);
 }
}
 int main(){
 

   int arr[]= {-2,3,4,-1,5,-12,6,0};

    int n = sizeof(arr)/sizeof(int);
  
    // cout<<"Unsorted array: "<<endl;
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
     cout<<"Sorted array: "<<endl;

    QuickSort(arr,0,n);
    for (int i = 0; i < n; i++)  
       cout<<arr[i]<<" ";

       return 0;
}  
 
