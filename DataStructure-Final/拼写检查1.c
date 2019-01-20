#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 3001
#define MULT 37
#define MAX 500000
#define SIZE 50

typedef struct Node{
	char word[SIZE];
	struct Node *link;
}*ptr,node;

typedef struct WNODE{
	char w[SIZE];
	int num;
	int add[MAX];
	struct WNODE *link;
}*wptr,wnode;

char dic[MAX][SIZE],s[SIZE],art[MAX][SIZE],buf[MAX*SIZE],tmp[SIZE];
int len,lenth;
ptr x[3010];
wptr p,q,r,list=NULL;

void get_dic(){
	FILE *in;
	int i=0,l;
	in=fopen("dictionary.txt","r");
	while(fgets(dic[i],MAX*SIZE,in)!=NULL){
		l=strlen(dic[i])-1;
		dic[i][l]='\0';
		i++;
	}
	len=i;
	fclose(in);
}
unsigned int nhash(char *str){
    unsigned int h=0;
    char *p;
    for(p=str;*p!='\0';p++)
        h=MULT*h+*p;
    return h%NHASH;
}

void creat_hashlist(){
	int i,id;
	ptr p,q;
	for(i=0;i<3010;i++){
		x[i]=NULL;
	}
	for(i=0;i<len;i++){
		id=nhash(dic[i]);
		if(x[id]==NULL){
			p=(ptr)malloc(sizeof(node));
			strcpy(p->word,dic[i]);
			p->link=NULL;
			x[id]=p;
		}
		else{
			for(q=x[id];q->link!=NULL;q=q->link)
				;
			p=(ptr)malloc(sizeof(node));
			strcpy(p->word,dic[i]);
			p->link=NULL;
			q->link=p;
		}
	}
}

void get_text(int cnt[]){
	FILE *in;
	int i,j=0,k=0;
	in=fopen("article.txt","r");
	fread(buf,1,MAX*SIZE,in);
	memset(tmp,0,sizeof(tmp));
	for(i=0;buf[i]!='\0';i++){
		if(buf[i]>='A'&&buf[i]<='Z'){
			if(tmp[0]=='\0'){
				cnt[j]=i;
			}
			tmp[k++]=buf[i]+32;
		}
		else if(buf[i]>='a'&&buf[i]<='z'){
			if(tmp[0]=='\0'){
				cnt[j]=i;
			}
			tmp[k++]=buf[i];
		}
		else if(tmp[0]!='\0'){
			tmp[k]='\0';
			strcpy(art[j++],tmp);
			k=0;
			memset(tmp,0,sizeof(tmp));
		}
	}
	if(tmp[0]!='\0'){
		tmp[k]='\0';
		strcpy(art[j++],tmp);
	}
	lenth=j;	
}

void insert(char str[],int place){
	p=(wptr)malloc(sizeof(wnode));
	strcpy(p->w,str);
	p->num=0;
	p->link=NULL;
	if(list==NULL){
		list=p;
		p->add[0]=place;
	}
	else{
		q=list;
		while(q!=NULL){
			if(strcmp(p->w,q->w)>0){
				r=q;
				q=q->link;
			}
			else if(strcmp(p->w,q->w)<0){
				if(q==list){
					p->link=q;
					p->add[0]=place;
					list=p;
				}
				else{
					p->link=q;
					r->link=p;
					p->add[0]=place;
				}
				break;
			}
			else if(strcmp(p->w,q->w)==0){
				q->num++;
				q->add[q->num]=place;
				free(p);
				break;
			}
		}
		if(q==NULL){
			r->link=p;
			p->add[0]=place;
		}
	}
}

void check(int cnt[]){
	int i,find,boolp;
	ptr p;
	for(i=0;i<lenth;i++){
		find=nhash(art[i]);
		boolp=1;
		for(p=x[find];p!=NULL;p=p->link){
			if(strcmp(p->word,art[i])==0){
				boolp=0;
				break;
			}
			else if(strcmp(p->word,art[i])>0){
				insert(art[i],cnt[i]);
				boolp=0;
				break;
			}
		}
		if(boolp){
			insert(art[i],cnt[i]);
		}
	}
}

void output(){
	int i;
	FILE *out;
	out=fopen("misspelling.txt","w");
	for(p=list;p!=NULL;p=p->link){
		fprintf(out,"%s",p->w);
		for(i=0;i<=p->num;i++){
			fprintf(out," %d",p->add[i]);
		}
		fprintf(out,"\n");
	}
	fclose(out);
}

int main(void){
	int cnt[MAX];
	get_dic();
	creat_hashlist();
	get_text(cnt);
	check(cnt);
	output();	
	return 0;
}
