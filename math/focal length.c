#include <stdio.h>

int main () {
	float u,v,f;
	
	printf("Enter the object distance, u: ");
	scanf("%f.2d",&u);
	
	printf("Enter the image distance, v: ");
	scanf("%f.2d",&v);
	
	f = (u*v)/(u+v);
	
	printf("Object distance, u = %.2fcm\nImage distance, v = %.2fcm\nFocal length, f = %.2fcm",u,v,f);
	
	return 0;
}
