#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int num;
	struct Node *link;
}node,*nodeptr;
int main(void){
	nodeptr p0=NULL,p=NULL,r=NULL,list=NULL;
	int n,m,q,i,k;
	scanf("%d %d %d",&n,&m,&q);
	for(i=0;i<n;i++){
		p=(nodeptr)malloc(sizeof(node));
		p->num=i+1;
		p->link=NULL;
		if(list==NULL){
			list=p;
		}
		else{
			r->link=p;
		}
		r=p;
	}
	p->link=list;                       //形成一个循环链表，即链表尾接链表头 
	p=list;                              //注意赋初值 
	for(i=0;i<q-1;i++){
		p0=p;
		p=p->link;
	}                                    //找到开始报数的地方 
	while(p->link!=p){                   //不是只有一个链结点的情况下 
		for(k=1;k<m;k++){
			p0=p;
			p=p->link;
		}
		p0->link=p->link;                //用两个变量p0和p进行删除操作 
		free(p);
		p=p0->link;                      //p指向被删除的链结点，p0指向上一链结点 
	} 
	printf("%d",p->num);
	free(p);
	return 0;
}
