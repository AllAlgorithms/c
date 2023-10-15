/*Representation of polynomial and summation of two polynomials*/
#include <stdio.h>
typedef struct 
{
    int exp;
    float coeff;
}terms;
void inputPoly(terms a[],int n)
{
    printf("Please enter the input in descending order of degrees \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient ");
        scanf("%f",&a[i].coeff);
        printf("Enter the exponent ");
        scanf("%d",&a[i].exp);
    }
}
displayPoly(terms a[],int n)
{
    printf("%fx^%d",a[0].coeff,a[0].exp);
    for(int i=1;i<n;i++)
    {
        printf("+%fx^%d",a[i].coeff,a[i].exp);
    }
}
int polyAdd(terms a[],terms b[],terms c[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<=n1&&j<=n2)
    {
        if(a[i].exp==b[j].exp)
        {
            c[k].exp=a[i].exp;
            c[k].coeff=a[i].coeff+b[j].coeff;
            i++;j++;k++;
        }
        else if(a[i].exp>b[j].exp)
        {
            c[k].exp=a[i].exp;
            c[k].coeff=a[i].coeff;
            i++;k++;
        }
        else if(a[i].exp<b[j].exp)
        {
            c[k].exp=b[j].exp;
            c[k].coeff=b[j].coeff;
            j++;k++;
        }
    }
    while(i<=n1)
    {
       c[k].exp=a[i].exp;
        c[k].coeff=a[i].coeff;
        i++;k++; 
    }
    while(j<=n2)
    {
      c[k].exp=b[j].exp;
      c[k].coeff=b[j].coeff;
      j++;k++;  
    }
    return k;
}
void main()
{
    terms a[10],b[10],r[20];
    int n1,n2;
    printf("Enter number of terms in first polynomial\n");
    scanf("%d",&n1);
    printf("Enter number of terms in second polynomial\n");
    scanf("%d",&n2);
    printf("Enter first polynomial\n");
    inputPoly(a,n1);
    printf("Enter second polynomial\n");
    inputPoly(b,n2);
    printf("first polynomial\n");
    displayPoly(a,n1);
    printf("\n");
    printf("second polynomial\n");
    displayPoly(b,n2);
    int k=polyAdd(a,b,r,n1,n2);
    printf("\n");
    displayPoly(r,k-1);
}
