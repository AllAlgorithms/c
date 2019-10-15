#include<stdio.h>
//Function to calculate the maximum sum of a sub-array of a given array
int maxSumarray(int a[], int size){
        int i;
        int max_sum_so_far=0;
        int max_ending_here = 0;
        
        for(i=0;i<size;i++){
        	max_ending_here = max_ending_here + a[i];
        	
        	if(max_ending_here < 0){
        		max_ending_here =0;
			}
		    if(max_sum_so_far < max_ending_here){
			  
			  max_sum_so_far = max_ending_here;
			
			}
			
		}

return max_sum_so_far;
}


int main(){
	
	int i,size;
	
	printf("Enter the size of the array ");
	scanf("%d",&size);
	
	int a[size];
	printf("\n Enter the elements of the array");
	for(i=0; i<size; i++){
		
		scanf("%d",&a[i]);		
	}
	 
	
	int max_sum = maxSumarray(a,size);
	
    printf("\n The Maximum Sum of the Sub Array is : %d",max_sum);
	
	
	return 0;
}
