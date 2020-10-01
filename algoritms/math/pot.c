#include <stdio.h>
float pot (int a, int b){
    if(b==0 && a !=0) 
        return 1;
    if(b>=1)
        return a * pot (a, b-1);
    if(b <= -1)
        return 1.0/a * pot (a, b+1);
    }
int main () {
    int a, b;
    float total;
    scanf ("%d %d", &a, &b);
        if(a == 0 && b <= 0){
            printf("indefinido\n");
        }
        else 
            total = pot(a,b);
            printf ("%f\n", total);
    return 0;
}
