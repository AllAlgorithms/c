//A number is an Armstrong number if it is equal to the sum of cube of its digits.
//e.g. 153 = 1*1*1 + 5*5*5 + 3*3*3
 
#include<stdio.h>

int main(){

  int num, rem, temp, sum = 0;;

  printf("Armstrong Number\n");

  printf("Enter the number:\n");
  scanf("%d",&num);

  temp = num;

  while(num > 0){
    rem = num % 10;
    sum += rem * rem * rem;
    num = num / 10;
  }

  printf("%d %d\n",sum, temp);

  if(temp == sum){
    printf("The number %d is an Armstrong number.\n", temp);
  }
  else
    printf("The number %d is not an Armstrong number.\n", temp);

  return 0;
}
