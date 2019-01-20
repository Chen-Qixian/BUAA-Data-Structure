#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 3001
#define MULT 37

typedef struct Node{
	char word[50];
	struct Node *link;
}*ptr,node;
char word_list[5000][50],s[50];
int len,cnt=0;
ptr x[5000];

void getlist(){
	int i=0,j;
	FILE *in;
	in=fopen("dictionary3000.txt","r");
	while((fgets(word_list[i],100,in))!=NULL){
		for(j=0;word_list[i][j]!='\n';j++)
			;
		word_list[i][j]='\0';
		i++;
	}	
	len=i;
	fclose(in);
}

void seq_search(){
	int i;
	for(i=0;i<len;i++){
		cnt++;
		if(strcmp(s,word_list[i])<=0){
			break;
		}
	}
	if(strcmp(s,word_list[i])==0){
		printf("1 %d",cnt);
	}
	else if(strcmp(s,word_list[i])<0){
		printf("0 %d",cnt);
	}
}

void binary_search(int left,int right){
	int mid,p=1;
	while(left<right){
		mid=(left+right)/2;
		cnt++;
		if(strcmp(s,word_list[mid])<0){
			right=mid-1;
		}
		else if(strcmp(s,word_list[mid])>0){
			left=mid+1;
		}
		else if(strcmp(s,word_list[mid])==0){
			printf("1 %d",cnt);
			p=0;
			break;
		}
	}
	mid=(left+right)/2;
	if(p&&strcmp(s,word_list[mid])!=0){
		cnt++;
		printf("0 %d",cnt);
	}
	else if(p&&strcmp(s,word_list[mid])==0){
		cnt++;
		printf("1 %d",cnt);
	}
}

void index_search(){
	int left,right,x,y,i;
	int add[30];              //数组定义为全局变量则REGSSIV！？ 
	for(i=0;i<len;i++){
		x=word_list[i][0]-96;
		add[x]=i;
	}
	add[0]=-1;
	add[24]=add[23];
	y=s[0]-97;
	if(y==23){
		printf("0 %d",cnt);
	}
	else{
		left=add[y]+1;
		right=add[y+1];
		binary_search(left,right);
	}	
}

unsigned int hash(char *str){
    unsigned int h=0;
    char *p;
    for(p=str;*p!='\0';p++)
        h=MULT*h+*p;
    return h%NHASH;
}

void hash_search(){
	int i,id,find,boolp=1;
	ptr p,q;
	for(i=0;i<5000;i++){
		x[i]=NULL;
	}
	for(i=0;i<len;i++){
		id=hash(word_list[i]);
		if(x[id]==NULL){
			p=(ptr)malloc(sizeof(node));
			strcpy(p->word,word_list[i]);
			p->link=NULL;
			x[id]=p;
		}
		else{
			for(q=x[id];q->link!=NULL;q=q->link)
				;
			p=(ptr)malloc(sizeof(node));
			strcpy(p->word,word_list[i]);
			p->link=NULL;
			q->link=p;
		}
	}
	find=hash(s);
	for(p=x[find];p!=NULL;p=p->link){
		cnt++;
		if(strcmp(p->word,s)==0){
			printf("1 %d",cnt);
			boolp=0;
			break;
		}
		else if(strcmp(p->word,s)>0){
			printf("0 %d",cnt);
			boolp=0;
			break;
		}
	}
	if(boolp){
		printf("0 %d",cnt);
	}
}

int main(void){
	int op;
	getlist();
	scanf("%s %d",s,&op);
	if(op==1) seq_search();
	else if(op==2) binary_search(0,len-1);
	else if(op==3) index_search();
	else if(op==4) hash_search();
	return 0;
} 
