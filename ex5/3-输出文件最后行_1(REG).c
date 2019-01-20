#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ord[10000],fname[10000],num[50],txt[10][1024];
int n=10;
void input(){
	int i,p=0,tail;
	scanf("tail %[^\n]",ord);
	for(i=0;i<strlen(ord);i++){
		if(ord[i]=='-'){
			p=1;
		}
		else if(ord[i]==' '){
			tail=i;
			break; 
		}
	}
	if(p){
		for(i=1;i<tail;i++){
			num[i-1]=ord[i];
		}
		n=atoi(num);
		for(i=tail+1;i<strlen(ord);i++){
			fname[i-tail-1]=ord[i];
		}
		fname[i-tail-1]='\0';
	}
	else{
		for(i=0;i<strlen(ord);i++){
			fname[i]=ord[i];
		}
	}
}
int main(void){
	int i=0,j,p=1; 
	input();
	FILE *in;
	in=fopen(fname,"r");
	while(fgets(txt[i],100,in)!=NULL){
		if(i==n){
			for(j=0;j<n;j++){
				strcpy(txt[j],txt[j+1]);
			}
			p=0;
		}
		if(p){
			i++;
		}
	}
	for(i=0;i<n&&txt[i]!=NULL;i++){
		for(j=0;txt[i][j]!='\0';j++){
			putchar(txt[i][j]);
		}
	}
	fclose(in);
	return 0;
}
