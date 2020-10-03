                                                     // Fractional Knapsack problem
# include<stdio.h> 
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, W;
   W = capacity;
   float total_weight;
   for (i = 0; i < n; i++)
      x[i] = 0.0;
    total_weight=0.0;
   for (i = 0; i < n; i++) {
      if (weight[i]+total_weight < W){
      	x[i] = 1.0;
      	total_weight = weight[i]+total_weight;
      	tp = tp + profit[i];
		}
        
      else {
         x[i] =  (W-total_weight)/weight[i];
         tp = tp +  (x[i] * profit[i]);
         total_weight = W;
      }
   
}
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum profit is:- %f", tp);
 
}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts  of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f",&weight[i]);
   }
    printf("\nEnter the profit  of each object:- ");
    for (i = 0; i < num; i++) {
      scanf("%f",&profit[i]);
   }  
   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
   printf("The weigth profit ratio is:-\n");
    for (i = 0; i < num; i++) {
      	printf("%f\t",weight[i]);
 }
 printf("\n");
  for (i = 0; i < num; i++) {
      	printf("%f\t",profit[i]);
 }
 printf("\n");
 for (i = 0; i < num; i++) {
      	printf("%f\t",ratio[i]);
 }
   knapsack(num, weight, profit, capacity);
   return 0;
}
