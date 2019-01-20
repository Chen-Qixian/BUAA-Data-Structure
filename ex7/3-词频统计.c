#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	char word[100];
	int num;
	struct Node *lchild,*rchild; 
}*tptr,tnode;
char ch,t[100];
int i=0;
void inorder(tptr T){
	if(T!=NULL){
		inorder(T->lchild);
		printf("%s %d\n",T->word,T->num);
		inorder(T->rchild);
	}
}
int main(void){
	FILE *in;
	tptr p,q,T=NULL;
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=EOF){
		if(isalpha(ch)){
			if(isupper(ch)){
				t[i++]=tolower(ch);
			}
			else{
				t[i++]=ch;
			}
		}
		else if(t[0]!='\0'&&(!isalpha(ch))){
			if(T==NULL){
				p=(tptr)malloc(sizeof(tnode));
				strcpy(p->word,t);
				p->num=1;
				p->lchild=NULL;
				p->rchild=NULL;
				T=p;
			}
			else{
				q=T;
				while(1){
					if(strcmp(t,q->word)==0){
						q->num++;
						break;
					}
					else if(strcmp(t,q->word)<0){
						if(q->lchild==NULL){
							p=(tptr)malloc(sizeof(tnode));
							strcpy(p->word,t);
							p->num=1;
							p->lchild=NULL;
							p->rchild=NULL;
							q->lchild=p;
							break;
						}
						else{
							q=q->lchild;
						}
					}
					else if(strcmp(t,q->word)>0){
						if(q->rchild==NULL){
							p=(tptr)malloc(sizeof(tnode));
							strcpy(p->word,t);
							p->num=1;
							p->lchild=NULL;
							p->rchild=NULL;
							q->rchild=p;
							break;
						}
						else{
							q=q->rchild;
						}
					}
				}
			}
			memset(t,0,sizeof(t));
			i=0;
		}
	}
	for(i=0,q=T;i<3&&q!=NULL;i++,q=q->rchild){ //就差一个判断控制条件，应该是q!=NULL. 
		printf("%s ",q->word);
	}
	printf("\n");
	inorder(T);
	return 0;
}
