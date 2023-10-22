#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bubblesort(int arr[], int n){
    for(int i = 0; i<n-1; i++){   //repeat it n-1 times
        for(int j = 0; j<n-i-1; j++){      //n-2 times
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
  

  // int i, arr[8];
   int arr[] = {-2,3,4,-1,5,-12,6,1};

   int n = sizeof(arr)/sizeof(int);
  
     cout<<"Sorted array: "<<endl;

bubblesort(arr,n);
for(int i = 0; i<n;i++){
    cout<<arr[i]<<",";
}

return 0;

}
