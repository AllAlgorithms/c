#include<stdio.h>
#define llo long long


/* This the implementation of 0-1 Knapsack problem, the problem statement is
Given weights and values of n items,
put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that
sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item, or don’t pick it. */


// The max function returns the maximum of the two inputs
llo max(llo a, llo b)
{
    return (a>b)?a:b;
}
// This function returns the maximum value that can be put in knapsack of capacity W
llo Knapsack(llo W, llo weight[], llo value[], llo n)
{
    // Base case
    if(n==0 || W==0)
        return 0;
    // If the weight of nth item is more than W,
    // this item cannot be included
    if(weight[n-1]>W)
        return Knapsack(W, weight, value, n-1);
    // Here we return the maximum of two cases,
    // (one) in which nth item is included
    // (two) in which nth item is not included
    else
        return max(value[n-1]+Knapsack(W-weight[n-1], weight, value, n-1), Knapsack(W, weight, value, n-1));
}
int main()
{
    llo n=0,W=0;
    // Enter the number of items
    scanf("%lld", &n);
    llo value[n];llo weight[n];
    // Enter the values associated with the items
    for(llo i=0;i<n;++i)
        scanf("%lld", &value[i]);
    // Enter the weights associated with the items
    for(llo i=0;i<n;++i)
        scanf("%lld", &weight[i]);
    // Enter the capacity of the knapsack
    scanf("%d", &W);
    printf("%d", Knapsack(W, weight, value, n));
    return 0;
}
