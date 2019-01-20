#include <stdio.h>
#include <stdlib.h>
int a1[10000],b1[10000],a2[10000],b2[10000];
typedef struct Node{
	int coe;
	int pow;
	struct Node *link;
}node,*nodeptr;
int readin(int a[],int b[]){
	int n;
	char ch;
	n=0;
	while(1){
		scanf("%d %d",&a[n],&b[n]);
		scanf("%c",&ch);
		n++;
		if(ch=='\n'){
			break;
		}
	}
	return n;
}
int main(void){
	int len1,len2,i,j;
	nodeptr p,q,r,list;
	len1=readin(a1,b1);
	len2=readin(a2,b2);
	p=(nodeptr)malloc(sizeof(node));
	p->coe=a1[0]*a2[0];
	p->pow=b1[0]+b2[0];
	p->link=NULL;
	list=r=p;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			if(i||j){		
				p=(nodeptr)malloc(sizeof(node));
				p->coe=a1[i]*a2[j];
				p->pow=b1[i]+b2[j];
				p->link=NULL;
				for(q=list;q!=NULL;r=q,q=q->link){
					if(p->pow>q->pow){
						if(q==list){
							p->link=list;
							list=p;
							break;
						}
						else{
							p->link=q;
							r->link=p;
							break;
						}
					}
					else if(p->pow==q->pow){
						q->coe+=p->coe;
						break;
					}
				}
				if(q==NULL){
					r->link=p;
				}
			}
		}
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%d %d ",p->coe,p->pow);
	}
	return 0;
}
