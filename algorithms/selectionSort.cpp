#include<iostream>
using namespace std;

void selection_sort(int a[], int n){

for(int i = 0; i< n; i++){
  
    int min_position = i;
    for(int j = i; j<n; j++){
        if(a[j]<a[min_position]){
            min_position = j;
        }
    }
    swap(a[min_position], a[i]);
}
}

int main(){




  int arr[] = {-2,3,4,-1,5,-12,6,1};

    int n = sizeof(arr)/sizeof(int);
  
     cout<<"Sorted array: "<<endl;

    selection_sort(arr,n);

       for(int i = 0; i<n;i++){
    cout<<arr[i]<<",";
}
    return 0;
}
