#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ord[10000],fname[10000],num[50],txt[10][1024];
int n;
int main(int argc,char *argv[]){
	int k;
	if(argc==2){
		strcpy(fname,argv[1]);
		n=10;
	}
	else if(argc==3){
		strcpy(fname,argv[2]);
		for(k=1;argv[1][k]!='\0';k++){
			num[k-1]=argv[1][k];
		}
		n=atoi(num);
	}
	int i=0,j,p=1; 
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
