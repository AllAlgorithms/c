#include<stdio.h>
int main(){
	int n,i,j,k;
		float array[10][10];
	float det,ratio;
	scanf("%d",&n);

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%f",&array[i][j]);
	}
}
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>i)
			{
			ratio=array[j][i]/array[i][i];
			for(k=0;k<n;k++)
			{
			array[j][k]=array[j][k]-ratio*array[i][k];
		}
		}
	
}
}
 det=1;
for(i=0;i<n;i++)


det=det*array[i][i];

printf("%f",det);
return 0;
}