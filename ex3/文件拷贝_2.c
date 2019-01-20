#include <stdio.h>
#include <string.h>
//问题：程序貌似能实现预期功能，平台检测报运行时错误（REG) 
char s[1000000],str[1000000];
int i,j;
int main(void){
	FILE *in,*out;
	in=fopen("fcopy.in","r");
	out=fopen("fcopy.out","w");
	fgets(s,900000,in);                //读入字符到s中 
	for(i=0,j=0;i<strlen(s)-1;i++){       
		if(s[i]!=' '&&s[i]!='\t'){                 //非空格正常读入 
			str[j]=s[i];
			j++; 
		}
		else{                             //空格则判断后一项是否空格或制表 
			if(s[i+1]!=' '&&s[i+1]!='\t'){  //不是则正常写入 
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
