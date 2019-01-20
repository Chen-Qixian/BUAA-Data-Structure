#include <stdio.h>
int main(void){
	int a,max=0,min=0,n,i;
	scanf("%d",&n);
	scanf("%d",&a);
	max=min=a;
	for(i=1;i<n;i++){
		scanf("%d",&a);
		if(a>max) max=a;
		if(a<min) min=a;
	}
	printf("%d %d\n",max,min);
	return 0;
}
