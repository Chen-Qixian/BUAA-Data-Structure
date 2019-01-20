#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char read[1000];
typedef struct Node{
	char word[1000];
	int num;
	struct Node *link;
}node,*nodeptr;
void del(void){
	memset(read,0,sizeof(read));
}
int main(void){
	FILE *in;
	char ch;
	int i=0;
	nodeptr p,q,r,list=NULL;
	in=fopen("article.txt","r");
	del();
	while((ch=fgetc(in))!=EOF){
		if(isalpha(ch)){
			if(isupper(ch)){
				ch=tolower(ch);
			}
			read[i++]=ch;
		}
		else{
			if(read[0]!='\0'){
				p=(nodeptr)malloc(sizeof(node));
				p->num=1;
				strcpy(p->word,read);
				del();
				i=0;
				if(list!=NULL){
					r=list;
					for(q=list;q!=NULL;r=q,q=q->link){
						if(strcmp(p->word,q->word)<0){
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
						else if(strcmp(p->word,q->word)==0){
							q->num+=p->num;
							break;
						}
					}
					if(q==NULL){
						r->link=p;
						p->link=NULL;
					}
				}
				else{
					list=p;
					p->link=NULL;
				}
			}
		}
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->num);
	}
	fclose(in);
	return 0;
}
