#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct Node{
	union Elem{
		int num;
		char op;
	}ele;
	int ty;
	struct Node *lchild,*rchild;
}*tptr,tnode;

union Stack{
	int num;
	char op;
}s[1000],r[1000];

int utype[1000],ut[1000],res[1000];
char stack[1000];
char ch,t[100];
int i=0,j=0,head=-1,k=0,l=-1;
tptr s0[1000];
tptr p=NULL;

int cal(char op,int a,int b){
	int result=0;
	switch(op){
		case '+':{
			result=a+b;
			break;
		}
		case '-':{
			result=a-b;
			break;
		}
		case '*':{
			result=a*b;
			break;
		}
		case '/':{
			result=a/b;
			break;
		}
		default:break;
	}
	return result;
}

void get_string(){
	t[0]='\0';
	do{
		ch=getchar();
		if(isdigit(ch)){
			t[i++]=ch;
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='('||ch==')'){
			if(t[0]!='\0'){
				utype[j]=0;
				r[j++].num=atoi(t);
			}
			utype[j]=1;
			r[j++].op=ch;
			i=0;
			memset(t,0,sizeof(t));
		}
	}while(ch!='=');
}

void postfix(){
	i=0;
	stack[++head]='#';
	while(i<j){
		if(utype[i]){
			if(r[i].op=='('){
				stack[++head]=r[i++].op;
			}
			else if(r[i].op==')'){
				while(stack[head]!='('){
					ut[k]=1;
					s[k++].op=stack[head--];
				}
				head--;
				i++;
			}
			else if(r[i].op=='*'||r[i].op=='/'){
				if(stack[head]!='*'&&stack[head]!='/'){
					stack[++head]=r[i++].op;
				}
				else{
					while(stack[head]=='*'||stack[head]=='/'){
						ut[k]=1;
						s[k++].op=stack[head--];
					}
					stack[++head]=r[i++].op;
				}
			}
			else if(r[i].op=='+'||r[i].op=='-'){
				if(stack[head]=='#'||stack[head]=='('){
					stack[++head]=r[i++].op;
				}
				else{
					while(stack[head]!='#'&&stack[head]!='('){
						ut[k]=1;
						s[k++].op=stack[head--];
					}
					stack[++head]=r[i++].op;
				}
			}
			else if(r[i].op=='='){
				while(stack[head]!='#'){
					ut[k]=1;
					s[k++].op=stack[head--];
				}
				i++;
			}
		}
		else{
			ut[k]=0;
			s[k++].num=r[i].num;
			i++;
		}		
	}
}

void get_val(){
	for(i=0;i<k;i++){
		if(ut[i]){
			res[l-1]=cal(s[i].op,res[l-1],res[l]);
			l--;
		}
		else{
			res[++l]=s[i].num;
		}
	}
}

void create_tree(){
	l=-1;
	for(i=0;i<k;i++){
		if(ut[i]){
			p=(tptr)malloc(sizeof(tnode));
			p->ele.op=s[i].op;
			p->ty=1;
			p->rchild=s0[l--];
			p->lchild=s0[l--];
			s0[++l]=p;
		}
		else{
			p=(tptr)malloc(sizeof(tnode));
			p->ele.num=s[i].num;
			p->ty=0;
			p->lchild=NULL;
			p->rchild=NULL;
			s0[++l]=p;
		}
	}
}

void output(){
	printf("%c ",p->ele.op);
	if(p->lchild!=NULL){
		if(p->lchild->ty){
			printf("%c ",p->lchild->ele.op);	
		}
		else{
			printf("%d ",p->lchild->ele.num);
		}		
	}
	if(p->rchild!=NULL){
		if(p->rchild->ty){
			printf("%c ",p->rchild->ele.op);	
		}
		else{
			printf("%d ",p->rchild->ele.num);
		}		
	}
	printf("\n%d",res[0]);	
}

int main(void){	
	get_string();
	postfix();
	get_val();
	create_tree();
	output();
	return 0;
}
