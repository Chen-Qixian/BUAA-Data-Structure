#include <stdio.h>
#include <string.h>
//���⣺����ò����ʵ��Ԥ�ڹ��ܣ�ƽ̨��ⱨ����ʱ����REG) 
char s[1000000],str[1000000];
int i,j;
int main(void){
	FILE *in,*out;
	in=fopen("fcopy.in","r");
	out=fopen("fcopy.out","w");
	fgets(s,900000,in);                //�����ַ���s�� 
	for(i=0,j=0;i<strlen(s)-1;i++){       
		if(s[i]!=' '&&s[i]!='\t'){                 //�ǿո��������� 
			str[j]=s[i];
			j++; 
		}
		else{                             //�ո����жϺ�һ���Ƿ�ո���Ʊ� 
			if(s[i+1]!=' '&&s[i+1]!='\t'){  //����������д�� 
				str[j]=' ';
				j++;
			}
		}
	}
	fputs(str,out);
	fclose(in);
	fclose(out);
	return 0;
} 
