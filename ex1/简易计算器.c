#include <stdio.h>
int main(void){
	int d1,d2,res=0;
	float div=0;
	char op;
	scanf("%d %d %c",&d1,&d2,&op);
	if(op=='+') printf("%d",res=d1+d2);
	else if(op=='-') printf("%d",res=d1-d2);
	else if(op=='*') printf("%d",res=d1*d2);
	else if(op=='/'){
		if(d1%d2==0) printf("%d",res=d1/d2);
		else {
			float d_1,d_2;
			d_1=d1;
			d_2=d2;
			printf("%.2f",div=d_1/d_2);
		}
	}
	else printf("wrong operation!");
	return 0;
} 
