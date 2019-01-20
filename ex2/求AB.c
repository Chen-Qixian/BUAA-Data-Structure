#include <stdio.h>
int main(void){
	int n,a,b,boolp=1;
	scanf("%d",&n);
	for(a=1;a<9;a++){
		for(b=a+1;b<10;b++){
			if((a*10+b)*(b*10+a)==n){
				printf("%d",a*10+b);
				boolp=0;
				//break;
			}
		}
	}
	if(boolp) printf("No Answer");
	return 0;
}
