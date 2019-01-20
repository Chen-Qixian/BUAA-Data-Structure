#include <stdio.h>
int main(void){
	int stack[200];
	int i=-1,op;
	while(1){
		scanf("%d",&op);
		if(op==-1){
			break;
		}
		else if(op==1){
			if(i>=99){
				scanf("%d",&stack[i]);
				printf("error ");
				continue;
			}
			else{
				i++;
				scanf("%d",&stack[i]);
			}
		}
		else if(op==0){
			if(i==-1){
				printf("error ");
				continue;
			}
			else{
				printf("%d ",stack[i]);
				i--;
			}
		}
	}
	return 0;
}
