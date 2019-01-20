#include <stdio.h>
#include <string.h>
//½øÖÆ×ª»»10->16 
int n,i;
char s[100];
void itoh(unsigned n,char s[]){
	int h,i=0;
	do{
  		h=n%16;
  		s[i++]=(h<=9)?h+'0':h+'A'-10;
 	}
	while((n/=16)!=0);
 	void reverse(char s[]);
 	reverse(s);
}

void reverse(char s[]){
 	int temp,i,j;
 	for(i=0,j=strlen(s)-1;i<j;i++,j--)
 	{
  		temp=s[i];
  		s[i]=s[j];
  		s[j]=temp;
 	}
}

int main(void){
	scanf("%d",&n); 
 	itoh(n,s);
	for(i=0;i<strlen(s);i++){
		printf("%c",s[i]);
 	}
 	return 0;
}

