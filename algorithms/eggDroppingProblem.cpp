// DP - EggDropping Memoization
#include<bits/stdc++.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

 int static dp[1001][1001];
 int EggDrop(int egg,int floor)
 {
     int dp[egg+1][floor+1];
     memset(dp,-1,sizeof(dp));
           /*if(egg==0)
              return 0;*/
           if(floor==0 || floor==1)
              return floor;
           if(egg==1)
              return floor;   // worst case scenario
           if(dp[egg][floor]!=-1)
              return dp[egg][floor];

   int ans=INT_MAX;
      for(int k=1;k<=floor;k++)
        {
            int low,high;
            if(dp[egg-1][k-1]!=-1)
                low=dp[egg-1][k-1];
            else{
                 low=EggDrop(egg-1,k-1);
                dp[egg-1][k-1]=low;
            }
            if(dp[egg][floor-k]!=-1)
                 high=dp[egg][floor-k];
            else{
                high=EggDrop(egg,floor-k);
                dp[egg][floor-k]=high;
            }
           int tempans=1+max(low,high);
           ans=min(ans,tempans);
        }
  return dp[egg][floor]=ans;
 }
int main()
{
    int egg,floor;
    cout<<"Total no of eggs and floor : ";
    cin>>egg>>floor;
    cout<<"\n Minimum no of attempts in worst case to find critical floor : "<<EggDrop(egg,floor)<<endl;
    return 0;
}
