#include <stdio.h>
#include <string.h>
//�ж��ַ������Ƿ�����һ�ַ����Ĳ��ֲ���������ĸ��ַ 
int main(void){
	char s[10000],t[10000];
	int i;
	scanf("%s",s);
	scanf("%s",t);
	int index(char s[],char t[]);
	i=index(s,t);
	printf("%d",i);
 	return 0;
}

int index(char s[],char t[]){
 	int i,j,k;
 	for(i=0;s[i]!='\0';i++){
  		for(j=i,k=0;j<i+strlen(t)&&s[j]==t[k];j++,k++)
   			;
  		if(t[k]='\0')
   		return (i);
 	}
 	return (-1);
}
