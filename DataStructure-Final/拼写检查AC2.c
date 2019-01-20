#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 26
#define SIZE 100000000
#define WORDLENTH 50

typedef struct Trie{
	char str[WORDLENTH];
	struct Trie *next[MAX];
	int v;
}*ptr,trie;

typedef struct Node{
	char str[WORDLENTH];
	struct Node *next[MAX];
	int w_id[3000];
	int w_num;
}*nodeptr,node;

char buf[SIZE],tmp[WORDLENTH];
ptr dic_root;
nodeptr wrong_root;
FILE *out;

void DFStree(nodeptr t){
	int i,j;
	if(t!=NULL){
		if(t->w_num){
			fprintf(out,"%s",t->str);
			for(j=0;j<t->w_num;j++){
				fprintf(out," %d",t->w_id[j]);
			}
			fprintf(out,"\n");
		}
		for(i=0;i<MAX;i++){
			if(t->next[i]!=NULL){
				DFStree(t->next[i]);
			}
		}
	}
}

void creat_trie(char x[]){
	int i,j,id;
	ptr p=dic_root,q;
	for(i=0;x[i]!='\0';i++){
		id=x[i]-'a';
		if(p->next[id]==NULL){
			q=(ptr)malloc(sizeof(trie));
			q->v=1;
			for(j=0;j<MAX;j++){
				q->next[j]=NULL;
			}
			strcpy(q->str,p->str);
			q->str[i]=x[i];
			q->str[i+1]='\0';
			p->next[id]=q;
			p=p->next[id];
		}
		else{
			p=p->next[id];
		}		
	}
	p->v=0;
}

void get_dic(){
	FILE *in;
	int i,j=0,num;
	if((in=fopen("dictionary.txt","r"))==NULL){
		printf("Can't open file!\n");
		return;
	}
	dic_root=(ptr)malloc(sizeof(trie));
	dic_root->v=1;
	memset(dic_root->str,0,sizeof(dic_root->str));
	for(i=0;i<MAX;i++){
		dic_root->next[i]=NULL;
	}	
	num=fread(buf,1,SIZE-10,in);
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<num;i++){
		if(buf[i]>='a'&&buf[i]<='z'){
			tmp[j++]=buf[i];
		}
		else if((buf[i]<'a'||buf[i]>'z')&&tmp[0]!='\0'){
			tmp[j]='\0';
			creat_trie(tmp);
			j=0;
			memset(tmp,0,sizeof(tmp));
		}
	}
	memset(buf,0,sizeof(buf));
    fclose(in);
}

void insert(char x[],int place){
	int i,j,id;
	nodeptr p=wrong_root,q;
	for(i=0;x[i]!='\0';i++){
		id=x[i]-'a';
		if(p->next[id]==NULL){
			q=(nodeptr)malloc(sizeof(node));
			for(j=0;j<MAX;j++){
				q->next[j]=NULL;
			}
			strcpy(q->str,p->str);
			q->str[i]=x[i];
			q->str[i+1]='\0';
			q->w_num=0;
			p->next[id]=q;
			p=p->next[id];
		}
		else{
			p=p->next[id];
		}		
	}
	p->w_id[p->w_num]=place;
	p->w_num++;
}

void check(char x[],int place){
	int i,boolp=1,id;
	ptr p=dic_root;
	for(i=0;x[i]!='\0';i++){
		id=x[i]-'a';
		if(p->next[id]==NULL){
			insert(x,place);
			boolp=0;
			break;
		}
		else{
			p=p->next[id];
		}
	}
	if(p->v&&boolp){
		insert(x,place);
	}
}

void get_text(){
	FILE *in;
	if((in=fopen("article.txt","r"))==NULL){
		printf("Can't open file!\n");
		return;
	}	
	int i,j=0,place,num;
	wrong_root=(nodeptr)malloc(sizeof(node));
	memset(wrong_root->str,0,sizeof(wrong_root->str));
	wrong_root->w_num=0;
	for(i=0;i<MAX;i++){
		wrong_root->next[i]=NULL;
	}
	num=fread(buf,1,SIZE-10,in);
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<num;i++){
		if(buf[i]>='a'&&buf[i]<='z'){
			if(tmp[0]=='\0'){
				place=i;
			}
			tmp[j++]=buf[i];
		}
		else if(buf[i]>='A'&&buf[i]<='Z'){
			if(tmp[0]=='\0'){
				place=i;
			}
			tmp[j++]=buf[i]+32;
		}
		else if(tmp[0]!='\0'){
			check(tmp,place);
			memset(tmp,0,sizeof(tmp));
			j=0;
		}
	}
}

int main(void){
	out=fopen("misspelling.txt","w");
	get_dic();
	get_text();
	DFStree(wrong_root);
	fclose(out);
	return 0;
}
