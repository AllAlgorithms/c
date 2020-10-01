#include<stdio.h>
int main()
{
	//Hashing using linear probing for collision resolution
	//Hash function is data%11
	int i,j=0,v,h,s,t,data,pos,b,posn,data_del,data_srch,k=0;
	int a[11];
	for(i=0;i<11;i++)
	{
	    //-2 specifies empty space
		a[i]=-2;
	}
	while(j!=5)
	{
		printf("Enter 1 to insert, 2 to Delete, 3 to Search, 4 to Display, 5 to Exit \n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				{
					//to find number of empty spaces
					s=0;
					for(i=0;i<11;i++)
					{
						if(a[i]==-2||a[i]==-1)
							s++;
					}
					printf("Enter data to insert\n");
					scanf("%d",&data);
					pos=data%11;
					if(a[pos]==-2||a[pos]==-1)
					{
						a[pos]=data;
					}
					else if(s!=0)
					{
						while((a[pos%11]!=-2)&&(a[pos%11]!=-1))
						{
							pos++;
							h++;
						}
						a[pos%11]=data;
					}
					else
					{
						printf("Data cannot be stored anymore\n");
					}

				}break;
			case 2:
				{
					printf("Enter data to delete\n");
					scanf("%d",&data_del);
					posn=data%11;
					if(a[posn]==data_del)
					{
							//flag for deleted element space is -1
							a[posn]=-1;
					}
					else
					{
						v=0;
						while(a[posn%11]!=data_del && v<13)
						{
							posn++;
							v++;
						}
						if (v==13)
							printf("Data not found, unable to delete\n");
						else if(a[posn%11]==data_del)
							a[posn%11]=-1;
					}
				}break;
			case 3:
				{

					printf("Enter data to search : ");
					scanf("%d",&data_srch);
					posn=data_srch%11;
					if(a[posn]==data_srch)
					{
							printf("Data is found at position %d \n",posn+1);
					}
					else
					{
						t=0;
						while(a[posn%11]!=data_srch&&a[posn%11]!=-2&&t!=12)
						{
							posn++;
							t++;
						}
						if(a[posn%11]==data_srch)
							printf("Data is found at position %d \n",posn+1);
						else
							printf("Data not found\n");
					}
				}break;
			case 4:
				{
					for(i=0;i<11;i++)
					{
						printf("%d\t",a[i]);
					}
					printf("\n");
				}break;
			case 5:
				{
					printf("Data successfully stored");
					for(i=0;i<11;i++)
					{
						printf("%d\t",a[i]);
					}
				}break;

			default:printf("Invalid input");
		}

	}

}
