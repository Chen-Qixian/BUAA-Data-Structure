#include <stdio.h>
int main(void){
	int n,dig=0,a[10]={0},i,j;
	scanf("%d",&n);
	while(n!=0){
		a[dig]=n%10;
		dig++;
		n/=10;
	}
	printf("%d\n",dig);
	for(j=dig-1;j>=0;j--)
		printf("%d",a[j]);
	printf("\n");
	for(i=0;i<dig;i++){
		printf("%d",a[i]);
	}		
	return 0;
}
