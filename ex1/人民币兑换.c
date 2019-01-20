#include <stdio.h>
int main(void){
	int sum,ten,five,two,one;
	scanf("%d",&sum);
	ten=sum/10;
	sum%=10;
	five=sum/5;
	sum%=5;
	two=sum/2;
	sum%=2;
	one=sum;
	printf("%d %d %d %d",ten,five,two,one);
	return 0;
}
