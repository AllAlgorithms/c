#include <stdio.h>

int max(int a, int b)
{
        if (a > b) return a;
        else return b;
}
int knapsack(int W, int weights[], int profits[], int n)
{
        int table[n+1][W+1];
        for(int i = 0; i <= n; i++) {
                for (int w = 0; w <= W; w++) {
                        if (i == 0 || w == 0) 
                                table[i][w] = 0;
                        else if(weights[i-1] <= w) 
                                table[i][w] = max(profits[i-1] + table[i-1][w-weights[i-1]], table[i-1][w]);
                        else
                                table[i][w] = table[i-1][w];
                }
        }
        return table[n][W];
}

int main()
{
        int profits[] = {10, 40, 30, 50};
        int weights[] = {5, 4, 6, 3};
        int W = 10;
        printf("%d", knapsack(W, weights, profits, 4));
        return 0;
}