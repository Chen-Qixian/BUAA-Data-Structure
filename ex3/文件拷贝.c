#include <stdio.h>
#include <string.h>
char s[1000000],str[1000000];
int i,j;
int main(void){
	FILE *in,*out;
	in=fopen("fcopy.in","r");
	out=fopen("fcopy.out","w");
	i=0;
	while((s[i]=fgetc(in))!=EOF){
		i++;
	}            
	for(i=0,j=0;i<strlen(s)-1;i++){       
		if(s[i]!=' '&&s[i]!='\t'){                 
			str[j]=s[i];
			j++; 
		}
		else{                             
			if(s[i+1]!=' '&&s[i+1]!='\t'){  
				str[j]=' ';
				j++;
			}
		}
	}
	for(i=0;i<strlen(str);i++){
		fputc(str[i],out);
	}
	fclose(in);
	fclose(out);
	for(i=0;i<strlen(str);i++){
		printf("%c",str[i]);
	}
	return 0;
} 
