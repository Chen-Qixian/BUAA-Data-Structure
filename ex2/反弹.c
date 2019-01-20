#include <stdio.h>
int main(void){
	double m,n,lenth=0,height,i;
	scanf("%lf %lf",&n,&m);
	height=n;
	lenth=height;
	height*=1.0/4;
	for(i=1;i<m;i++) {
		lenth+=height*2;
		height*=1.0/4;
	}
	printf("%.2lf\n",lenth);
	printf("%.2lf",height);
	return 0;
} 
