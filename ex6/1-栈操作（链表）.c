#include <stdio.h>
#include <stdlib.h>
#define Maxlen 100
typedef struct Node{
	int data;
	struct Node *link;
}*nodeptr,node;
int main(void){
	int op,len=0;
	nodeptr p,list=NULL;
	while(1){
		scanf("%d",&op);
		if(op==-1){
			break;
		}
		else if(op==1){
			len++;
			if(len>=Maxlen){
				printf("error ");
				continue;
			}
			p=(nodeptr)malloc(sizeof(node));
			scanf("%d",&p->data);
			p->link=list;
			list=p;		
		}
		else if(op==0){
			if(list==NULL){
				printf("error ");
				continue;
			}
			else{
				printf("%d ",list->data);
				list=list->link;
				len--;
			}
		}
	}
	return 0;
} 
