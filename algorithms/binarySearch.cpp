#include<iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high){
    while(low<=high){
        int mid = (high+low)/2;
        if(array[mid] == x) return mid;

        if(array[mid]<x) low = mid+1;
        else high = mid - 1;
    }
    return -1;

}

int main(){
    int array[] = {1,2,3,4,5};
    int x = 12;
    int n = sizeof(array)/sizeof(int);

    int result = binarySearch(array, x, 0, n-1);
    if(result == -1) cout<<"not found"<<endl;
    else cout<<"element is found at index "<<result<<endl;

    return 0;
}
