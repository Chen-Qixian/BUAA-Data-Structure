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
	p->link=list;                       //�γ�һ��ѭ������������β������ͷ 
	p=list;                              //ע�⸳��ֵ 
	for(i=0;i<q-1;i++){
		p0=p;
		p=p->link;
	}                                    //�ҵ���ʼ�����ĵط� 
	while(p->link!=p){                   //����ֻ��һ������������� 
		for(k=1;k<m;k++){
			p0=p;
			p=p->link;
		}
		p0->link=p->link;                //����������p0��p����ɾ������ 
		free(p);
		p=p0->link;                      //pָ��ɾ��������㣬p0ָ����һ����� 
	} 
	printf("%d",p->num);
	free(p);
	return 0;
}
