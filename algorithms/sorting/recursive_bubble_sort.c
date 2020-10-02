/* C implementation Recursive Bubble Sort */
#include<stdio.h> 

///bubble
void swap(int *n1,int *n2){
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
}

void bubbleSort(int V[],int vt,int pos,int nBubble,int change){
    if(pos==vt-1-nBubble){
        if(change>0){
            bubbleSort(V,vt,0,nBubble+1,0);
        }
        return;
    }

    if(V[pos]>V[pos+1]){
        swap(&V[pos],&V[pos+1]);
        change++;
    }
    bubbleSort(V,vt,pos+1,nBubble,change);
}

// test
int main()
{
  int arr[] = {46, 24, 33, 10, 2, 81, 50};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n,0,0,0);
  printf("Sorted array: \n");
  for(int i=0;i<7;i++){
      printf("%d ",arr[i]);
  }
  return 0;
}