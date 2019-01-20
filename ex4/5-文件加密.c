#include <stdio.h>
#include <ctype.h>
#include <string.h>
char kw[60],key[26];
void get_key(void){
	int i,j,k,p;
	for(i=0,j=0;kw[i]!='\0';i++){
		p=1;
		for(k=0;k<i;k++){
			if(kw[k]==kw[i]){
				p=0;
				break;
			}
		}
		if(p){
			key[j++]=kw[i];
		}
	}
	if(j<26){
		for(i='z';i>='a';i--){
			p=1;
			for(k=0;k<j;k++){
				if(key[k]==i){
					p=0;
					break;
				}
			}
			if(p){
				key[j++]=i;
			}
		}
	}
//	puts(key);
}
int main(void){
	FILE *in,*out;
	char ch,temp;
	scanf("%s",kw);
	get_key();
	if((in=fopen("encrypt.txt","r"))==NULL){
		printf("Can't open the file!\n");
		return 1;
	}
	if((out=fopen("output.txt","w"))==NULL){
		printf("Can't open the file!\n");
		return 1;
	}
	while((ch=fgetc(in))!=EOF){
		if(islower(ch)){
			temp=key[ch-'a'];
			fputc(temp,out);
		}
		else fputc(ch,out);
	}
	fclose(in);
	fclose(out);
	return 0;
} 
