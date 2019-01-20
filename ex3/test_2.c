#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char cal[1000];


int main(void){
	
		int i,j;
		gets(cal);
		for(i=0,j=0;cal[i]!='\0';i++)
			if(cal[i]!=' ')
				cal[j++]=cal[i];
		cal[j]='\0';
		
	for(i=0;i<strlen(cal);i++){
		printf("%c",cal[i]);
	}
	return 0;
}
