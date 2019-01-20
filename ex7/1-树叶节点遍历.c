#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int num;
	int high;
	struct node *lchild,*rchild;
}TNode,*Tptr;
void inorder(Tptr T){
	if(T!=NULL){
		inorder(T->lchild);
		if(T->lchild==NULL&&T->rchild==NULL){
			printf("%d %d\n",T->num,T->high);
		}
		inorder(T->rchild);
	}
}
int main(void){
	int n,i;
	Tptr p,q=NULL,T=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p=(Tptr)malloc(sizeof(TNode));
		scanf("%d",&p->num);
		p->lchild=NULL;
		p->rchild=NULL;
		p->high=1;
		if(T==NULL){
			T=p;
		}
		else{
			q=T;
			while(1){
				if(p->num<q->num){
					if(q->lchild==NULL){
						p->high++;
						q->lchild=p;
						break;
					}
					else{
						q=q->lchild;
						p->high++;
					}
				}
				else{
					if(q->rchild==NULL){
						p->high++;
						q->rchild=p;
						break;
					}
					else{
						q=q->rchild;
						p->high++;
					}
				}
			}
		}
	}
	inorder(T);
	return 0;
}
