#include <stdio.h>
#include <string.h>
//É¾³ý×Ö·û´®ÖÐµÄÄ³¸ö×Ö·û 
char s[10000],c;
void squeez(char s[],char c)
{
 	int i,j;
 	for(i=j=0;s[i]!='\0';i++)
  		if(s[i]!=c)
   			s[j++]=s[i];
 	s[j]='\0';
}

int main(void){
	int i;
	scanf("%s %c",s,&c);
 	squeez(s,c);
	for(i=0;i<strlen(s);i++){
		printf("%c",s[i]);
 	}
 	return 0;
}
