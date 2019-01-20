#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define Size 100 
char search[30],cmp[30],del[30],read[Size],put[Size][Size],temp[100];
int hide=-1,head,tail;
void change(char x[]){
	int i;
	for(i=0;i<strlen(x);i++){
		if(isupper(x[i])){
			x[i]=tolower(x[i]);
		}
	}
}
void set(){
	int i,j,p=0;
	for(i=0;i<strlen(search);i++){
		if(search[i]=='['){
			head=i;
			p=1;
		}
		else if(search[i]==']'){
			tail=i;
		}
		else if(search[i]=='*'){
			hide=i;
		}
	}
	if(p){
		for(i=0;i<tail-head-1;i++){            //方括号内比较字符 
 			cmp[i]=search[head+1+i];
		}
	}
	else{
		head=tail=strlen(search);
	}
	for(i=j=0;i<strlen(search);i++){         //删除后剩余逐字比较串 
		if(i<head||i>tail){
			del[j++]=search[i];
		}
		if(i==head){
			del[j++]=' ';
		}
	}
	del[j]='\0';
	change(del);
	change(cmp);
	for(i=0;i<Size;i++){
		memset(put[i],0,sizeof(put[i]));     //初始化put 数组为空，以便判空输出时的需要 
	}
}
int main(void){
	FILE *in,*out; 
	in=fopen("0.txt","r");
	out=fopen("q.txt","w");
	scanf("%s",search);
	set();
	int i,j,k,l,p,n,line_num=0;
	while(fgets(read,Size,in)!=NULL){
		line_num++;
//		puts(read);
		j=k=0;
		n=0;
		while(read[j]!='\n'){
			if(read[j]==del[k]||read[j]+32==del[k]){
				temp[k]=read[j];
				k++;
			}
			else if((k!=hide)&&k!=head&&(read[j]!=del[k]&&(read[j]+32)!=del[k])){
				k=0;
				memset(temp,0,sizeof(temp));
			}
			else if(k==head){
				if(cmp[0]=='^'){
					p=1;
					for(l=1;l<strlen(cmp);l++){
						if(read[j]==cmp[l]||read[j]+32==cmp[l]){
							p=0;
							break;
						}
					}
					if(p){
						temp[k]=read[j];
						k++;
					}
					else{
						memset(temp,0,sizeof(temp));
						k=0;
					}
				}
				else{
					p=0;
					for(l=0;l<strlen(cmp);l++){
						if(read[j]==cmp[l]||(read[j]+32)==cmp[l]){
							p=1;
							break;
						}
					}
					if(p){
						temp[k]=read[j];
						k++;
					}
					else{
						memset(temp,0,sizeof(temp));
						k=0;
					}
				}
			}
			if((hide==-1)&&k==strlen(del)){
				for(l=0;l<k;l++,n++){
					put[line_num][n]=temp[l];
				}
				put[line_num][n++]=',';
				k=0;
//				puts(temp);
//				puts(put[line_num]);
				memset(temp,0,sizeof(temp));
				j--;
			}
			j++;
		}
		put[line_num][n-1]='\0';
		memset(read,0,sizeof(read));				
	}
	for(i=1;i<=line_num;i++){
		if(put[i][0]!='\0'){
			fprintf(out,"%d:%s\n",i,put[i]);
		}
	}	
//	puts(search);
//	puts(cmp);
//	puts(del);
//	printf("%d",hide);
	fclose(in);
	fclose(out); 
	return 0;
} 
