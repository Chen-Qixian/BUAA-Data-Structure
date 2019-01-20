#include <stdio.h>
char t[100000],s[300],out[300];
char ch;
int p0=1,p1=1,p2=1,p3=1,p4=1,lnt=0,ln=1;
void del_area(int i){
	if(t[i]=='/'&&t[i+1]=='/'){
		p1=0;
	}
	else if(t[i]=='/'&&t[i+1]=='*'){
		p2=0;
	}
	else if(t[i]=='*'&&t[i+1]=='/'){
		p2=1;
	}		
	else if(t[i]=='\n'){
		p1=1;
	}
	else if(t[i]=='"'&&p3){
		p3=0;
	}
	else if(t[i]=='"'&&(!p3)){
		p3=1;
	}
	else if(t[i]=='\''&&p4&&p3){
		p4=0;
	}
	else if(t[i]=='\''&&(!p4)&&p3){
		p4=1;
	}
}
int judge(void){
	return p1&&p2&&p3&&p4;
}
int main(void){
	FILE *in;
	in=fopen("example.c","r");
	int i=0,head=-1,j=0;
	while((ch=fgetc(in))!=EOF){
		t[i++]=ch;
	}
	t[i]='\0';
	for(i=0;t[i]!='\0';i++){
		del_area(i);
		if((t[i]=='('||t[i]=='{')&&judge()){
			s[++head]=t[i];
			out[j++]=t[i];
			if(head==0){
				lnt=ln;
			}
		}
		else if(t[i]=='\n'){
			ln++;
		}
		else if(t[i]==')'&&judge()){
			out[j++]=t[i];
			if(s[head]=='('){
				head--;
			}
			else{
				printf("without maching ')' at line %d",ln);
				p0=0;
				break;
			}
		}
		else if(t[i]=='}'&&judge()){
			out[j++]=t[i];
			if(s[head]=='{'){
				head--;
			}
			else{
				printf("without maching '}' at line %d",ln);
				p0=0;
				break;
			}
		}
	}
	out[j]='\0';
	if(p0){
		if(head==-1){
			puts(out);
		}
		else{
			if(s[head]=='{'){
				printf("without maching '{' at line %d",lnt);
			}
			else if(s[head]=='('){
				printf("without maching '(' at line %d",lnt);
			}
		}	
	}
	return 0;
}
