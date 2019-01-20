#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXW 50
#define MAXN 250000
#define MAX 10000000

typedef struct Node{
	char word[MAXW];
	int u;
	int len;
	int num;
	int w_id[1500];
	struct Node	*next[26];
}*ptr,node;

node x[MAXN];
char buf[MAX],Buf[MAX],tmp[MAXW];
int used=0;
ptr root;
FILE *out;

void DFS(ptr t){
	int i;
	if(t!=NULL){
		if(t->u==1){
			fprintf(out,"%s",t->word);
			for(i=0;i<t->num;i++){
				fprintf(out," %d",t->w_id[i]);
			}
			fprintf(out,"\n");
		}
		for(i=0;i<26;i++){
			if(t->next[i]!=NULL){
				DFS(t->next[i]);
			}
		}
	}
}

void get_text(void){
	FILE *in;
	int n;
	in=fopen("article.txt","r");
	n=fread(buf,1,MAX-1,in);
	buf[n]='\0';
	fclose(in);
}

void insert(char tmp[],int id){
	
	
}

void creat_tree(void){
	int i0,i,j=0,id;
	root=&x[used++];
	root->u=0;
	root->len=0;
	root->num=0;
	ptr p=root,q;
	memset(tmp,0,sizeof(tmp));
	for(i=0;buf[i]!='\0';i++){
		if(buf[i]>='a'&&buf[i]<='z'){
			if(tmp[0]=='\0'){
				id=i;
			}
			tmp[j++]=buf[i];
		}
		else if(buf[i]>='A'&&buf[i]<='Z'){
			if(tmp[0]=='\0'){
				id=i;
			}
			tmp[j++]=buf[i]+32;
		}
		else if(tmp[0]!='\0'){
			tmp[j]='\0';
			for(i0=0;tmp[i0]!='\0';i0++){
				if(p->next[tmp[i0]-'a']==NULL){
					q=&x[used++];
					q->u=0;
					strcpy(q->word,p->word);
					q->len=p->len+1;
					q->word[q->len-1]=tmp[i0];
					q->word[q->len]='\0';
					p->next[tmp[i0]-'a']=q;
					p=q;
				}
				else{
					p=p->next[tmp[i0]-'a'];
				}	
			}
			p->u=1;
			if(p->num<1500)
				p->w_id[p->num++]=id;
			memset(tmp,0,sizeof(tmp));
			j=0;
		}
	}
	if(tmp[0]!='\0'){
		tmp[j]='\0';
		insert(tmp,id);
	}
}

void del(char tmp[]){
	int i,judge=1;
	ptr p=root;
	for(i=0;tmp[i]!='\0';i++){
		if(p->next[tmp[i]-'a']!=NULL){
			p=p->next[tmp[i]-'a'];
		}
		else{
			judge=0;
			break;
		}
	}
	if(judge){
		p->u=0;
	}
}

void get_dic(void){
	FILE *in;
	int i,j=0,n;
	in=fopen("dictionary.txt","r");
	n=fread(Buf,1,MAX,in);
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<n;i++){
		if(Buf[i]>='a'&&Buf[i]<='z'){
			tmp[j++]=Buf[i];
		}
		else if(tmp[0]!='\0'){
			del(tmp);
			memset(tmp,0,sizeof(tmp));
			j=0;
		}
	}
	if(tmp[0]!='\0'){
		tmp[j]='\0';
		del(tmp);
	}
	fclose(in);
}

int main(void){
	out=fopen("misspelling.txt","w");
	get_text();
	creat_tree();
	get_dic();
	DFS(root);
	fclose(out);
	return 0;
}
