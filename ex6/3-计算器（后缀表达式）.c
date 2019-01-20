#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int maxlen;
int s1[1000],n[1000]={0},s[1000]={0};
char op[1000],ch,num[5],s2[1000],s3[1000];

int isopr(char x){
	return (x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')')?1:0;
}
int isnum(char x){
	return (x>='0'&&x<='9')?1:0;
}
void input(void){
	int i=0,j=0;
	for(i=0;i<999;i++){
		op[i]='a';
		s2[i]='a';
		n[i]=-1;
		s1[i]=-1;
	}
	i=0;
	s3[0]='#';
	while((ch=getchar())!='='){
		if(isopr(ch)&&num[0]!='\0'){
			n[i++]=atoi(num);
			j=0;
			memset(num,0,sizeof(num));
			op[i++]=ch;
		}
		else if(isopr(ch)&&num[0]=='\0'){
			op[i++]=ch;
		}
		else if(isnum(ch)){
			num[j++]=ch;
		}
	}
	if(num[0]!='\0'){
		n[i++]=atoi(num);
	}
	maxlen=i;
}
int o(int a,int b,char c){
	int result=0;
	switch(c){
		case '+':{
			result=a+b;
			break;
		}
		case '-':{
			result=a-b;
			break;
		}
		case '*':{
			result=a*b;
			break;
		}
		case '/':{
			result=a/b;
			break;
		}
		default:break;
	}
	return result;
}
int main(void){
	int i,j=0,k=-1,l=-1;
	input();	
	for(i=0;i<maxlen;i++){
		if(n[i]>=0){
			s1[++k]=n[i];
		}
		else if(op[i]!='a'){
			if(op[i]=='*'||op[i]=='/'){
				if(s3[j]=='#'||s3[j]=='('||s3[j]=='+'||s3[j]=='-'){
					s3[++j]=op[i];
				}
				else{
					while(s3[j]=='*'||s3[j]=='/'){
						s2[++k]=s3[j];
						j--;
					}
					s3[++j]=op[i];
				}
			}
			else if(op[i]=='+'||op[i]=='-'){
				if(s3[j]=='#'||s3[j]=='('){
					s3[++j]=op[i];
				}
				else{
					while(s3[j]!='('&&s3[j]!='#'){
						s2[++k]=s3[j];
						j--;
					}
					s3[++j]=op[i];
				}
			}
			else if(op[i]=='('){
				s3[++j]=op[i];
			}
			else if(op[i]==')'){
				while(s3[j]!='('){
					s2[++k]=s3[j];
					j--;
				}
				j--;
			}
		}
	}
	for(;j>0;j--){
		s2[++k]=s3[j];
	}
	s2[++k]='\0';
	for(i=0;i<k;i++){
		if(s1[i]!=-1){
			s[++l]=s1[i];
		}
		else if(s2[i]!='a'){
			s[l-1]=o(s[l-1],s[l],s2[i]);
			l--;
		}
	}
	printf("%d",s[0]);
	return 0;
} 





























