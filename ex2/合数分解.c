#include <stdio.h>
#include <math.h>
int main(void){
	int n,i,boolp,j,total;
	scanf("%d",&n);
	total=n;
	for(i=2;i<=total;){
		if(n%i==0){
			boolp=1;
			for(j=2;j<=sqrt(i);j++){
				if((i%j)==0){
					boolp=0;
					break;
				}
			}
			if(boolp){
				n/=i;
				printf("%d ",i);
			}
		}
		else{
			i++;
		}	
	}
	return 0;
}
