                    // make a chnage problem
#include<stdio.h>
#include<string.h>
int min(int a, int b) { 
   if(a<b){   
   	return a;
	}
	else{	
		return b;
	}
} 
int main(){
	int no_of_denomination,amount,denomination[100],i,j;
	int ch[20][20],min_coin=99999999;;
	printf("Enter the amount you want to exchange:");
	scanf("%d",&amount);
	printf("Enter the no. of denomination:");
	scanf("%d",&no_of_denomination);
	printf("Denomination are:\n");
	for(i=1;i<=no_of_denomination;i++){
		scanf("%d",&denomination[i]);
	}
	int ch_amount[amount+1];
   int t[no_of_denomination][amount+1];
   for(i=1;i<=no_of_denomination;i++){
   	for(j=0;j<amount+1;j++){
   	 if(j==0){
   	 	t[i][j]=0;
		 }
	    else if(denomination[i]==1){
			t[i][j]=1+t[i][j-1];
		}
		else if(j<denomination[i]){
			t[i][j]=t[i-1][j];
		}
		else{
			t[i][j]=min(t[i-1][j],1+t[i][j-denomination[i]]);
		}
			printf("t[%d][%d]=%d\n",i,j,t[i][j]);
   	    	min_coin=min(t[i][amount],t[i][amount]);
		}
	}
   printf("minimum no. of coin required: %d",min_coin);
	return 0;
}

