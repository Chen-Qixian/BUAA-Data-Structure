#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct Node{
	int wei;
	char ch;
	int cd[100];
	int hei;
	struct Node *link,*lchild,*rchild;
}*tptr,node;

int freq[128]={0};
int code[128][100];
int convert[100000];
tptr p,q,r,list=NULL;

void count(){
	FILE *in;
	char c;
	int i;
	in=fopen("input.txt","r");
	while((c=fgetc(in))!=EOF){
		if(c!='\n'){
			freq[(int)c]++;
		}
	}
	freq[0]++;
	fclose(in);
	for(i=0;i<128;i++){
		if(freq[i]){
			printf("%c %d\n",i,freq[i]);
		}
	}
}

void sort(){
	int i;
	for(i=0;i<128;i++){
		if(freq[i]){
			p=(tptr)malloc(sizeof(node));
			p->wei=freq[i];
			p->ch=(char)i;
			p->hei=0;
			p->lchild=p->rchild=p->link=NULL;
			if(list==NULL){
				list=p;
			}
			else{
				q=r=list;
				while(q!=NULL){
					if(p->wei<q->wei){
						if(q==list){
							p->link=q;
							list=q=p;
						}
						else{
							r->link=p;
							p->link=q;
						}
						break;
					}
					else{
						r=q;
						q=q->link;
					}
				}
				if(q==NULL){
					r->link=p;
				}					
			}			
		}
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%c %d\n",p->ch,p->wei);
	}
	printf("**********\n");
}

void inorder(tptr t){
	if(t!=NULL){
		inorder(t->lchild);
		if(t->lchild==NULL&&t->rchild==NULL){
			printf("%c %d %d\n",t->ch,t->wei,t->hei);
		}
		inorder(t->rchild);
	}
}

void htree(){
	while(1){
		r=list;
		q=list->link;
		p=(tptr)malloc(sizeof(node));
		p->wei=r->wei+q->wei;
		p->ch='#';
		p->lchild=r;
		p->rchild=q;
		p->link=NULL;
		if(q->link==NULL){
			list=p;
			break;
		}
		else{
			list=q=q->link;
			while(q!=NULL){
				if(p->wei<q->wei){
					if(q==list){
						p->link=q;
						list=p;
					}
					else{
						p->link=q;
						r->link=p;
					}
					break;
				}
				else{
					r=q;
					q=q->link;
				}
			}
			if(q==NULL){
				r->link=p;
			}
		}
	}
	inorder(list);
}

void encode(tptr t){                           //传进来的是树根节点list 
	int i;
	if(t!=NULL){
		if(t->lchild!=NULL){
			for(i=0;i<t->hei;i++){             //t->hei是当前层的高度 
				t->lchild->cd[i]=t->cd[i];      //循环“抄”上一层编码 
			}
			t->lchild->cd[i]=0;                //cd[i]记录编码最后一位 
			t->lchild->hei=i+1;                //下一层层数+1 
		}
		if(t->rchild!=NULL){
			for(i=0;i<t->hei;i++){
				t->rchild->cd[i]=t->cd[i];
			}
			t->rchild->cd[i]=1;
			t->rchild->hei=i+1;
		}
		if(t->lchild==NULL&&t->rchild==NULL){  //如果是叶子就把编码记录到二维数组中 
			for(i=0;i<t->hei;i++){               //第一维坐标是叶子的字符对应的ASCII码 
				code[(int)t->ch][i]=t->cd[i];
			}
			code[(int)t->ch][i]=2;              //这个是后面输出检测用的，随后一位标记2表示结束 
		}
		encode(t->lchild);                   //递归，不知道是不是这里错了。。。（死循环） 
		encode(t->rchild);
	}
}

int exchange(){
	FILE *in;
	char c;
	int i=0,j,temp;
	in=fopen("input.txt","r");
	while((c=fgetc(in))!=EOF){
		if(c!='\n'){
			j=0;
			while(code[(int)c][j]!=2){
				convert[i++]=code[(int)c][j++];
			}
		}
	}
	j=0;
	while(code[0][j]!=2){
		convert[i++]=code[0][j++];
	}
	if(i%8){
		temp=8-i%8;
		for(j=0;j<temp;j++){
			convert[i++]=0;
		}
	}
	for(j=0;j<i;j++){
		printf("%d",convert[j]);
	}
	fclose(in);
	return i;
}

void output(int len){
	FILE *out;
	out=fopen("output.txt","w");
	int d,i=0,j,k,n;
	n=len/8;
	for(j=0;j<n;j++){
		d=0;
		for(k=7;k>=0;k--){
			d+=convert[i++]*pow(2,k);
		}
		printf("%x",d);
		fputc(d,out);
	}
	fclose(out);
}

int main(void){
	int i,j,len;
	count();
	sort();
	htree();
	encode(list);
    for(i=0;i<128;i++){
		if(freq[i]){
			j=0;
			printf("%c ",i);
			while(code[i][j]!=2){
				printf("%d",code[i][j]);
				j++;
			}
			printf("\n");
		}
	}
	len=exchange();
	output(len);
	return 0;
}
