#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int cd[10];
}*node,n;
int main(void){
	node p;
	p=(node)malloc(sizeof(n));
	p->cd[1]=0;
	printf("%d",p->cd[1]);
	return 0;
}
