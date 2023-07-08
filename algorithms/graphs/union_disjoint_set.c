//
// Created by Ritik Narayan on 08-07-2023.
//
#include <stdio.h>
#include <string.h>
int find_set(int arr[],int n){
    if(arr[n]==n) return n;
    return arr[n] = find_set(arr,arr[n]);
}
void union_sets(int arr[],int u,int v){
    u = find_set(arr,u);
    v = find_set(arr,v);
    if(u!=v)
        arr[v] = u;
}
int main(){
    int n,arr[99999],q,u,v;
    memset(arr,-1,99999*sizeof(int));
    printf("Enter the total element := ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++) arr[i] = i;
    printf("Enter the number of edges := ");
    scanf("%d",&q);
    while(q--){
        printf("Enter the edge relation := ");
        scanf("%d%d",&u,&v);
        union_sets(arr,u,v);
    }
    for(int i=1;i<=n;i++) printf("%d is in %d group\n",i, find_set(arr,i));
}