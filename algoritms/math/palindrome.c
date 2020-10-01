#include <stdio.h>

int main (){
    int n, aux = 0, reverse = 0;
    scanf("%d", &n);
    aux = n;
    while(aux != 0){
        reverse = reverse*10 + aux%10;
        aux = aux/10;
    }
    if(reverse == n)
        printf("%d is a palindrome!\n", n);
    else 
        printf("% isn't a palindrome!\n", n);
    
    return 0;
}
