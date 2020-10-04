#include <stdio.h>
#include <math.h>

double areabyside(double, double, double);

double areabyheight(double, double);

int main()
{
    int n;
    printf("Enter   1.For Sides \n\t2. For Height and base\n"); 
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        {
            printf("Enter the sides of triangle: ");
            double a, b, c;
            scanf("%lf%lf%lf", &a, &b, &c);
            double area = areabyside(a,b,c);
            printf("Area of the given Triangle is %.2lf", area);
            break;
        }
    case 2:
        {
            printf("Enter the height and base of triangle: ");
            double h, b;
            scanf("%lf%lf", &h, &b);
            double area = areabyheight(h ,b);
            printf("Area of the given Triangle is %.2lf", area);
            break;
        }
    }
return 0; 
}

double areabyside(double a, double b, double c)
{
    double s, area;
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
double areabyheight(double h, double b)
{
    double area;
    area = (h*b)/2;
    return area;
}
