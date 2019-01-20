#include <stdio.h>
#include <string.h>
#include <ctype.h>
char ori[1000],rep[1000],t[1000];
int main(void){
	FILE *in,*out;
	int len_o,i,p=1;
	char ch;
	in=fopen("filein.txt","r");
	out=fopen("fileout.txt","w");
	scanf("%s %s",ori,rep);
	len_o=strlen(ori);
	for(i=0;i<len_o;i++){
		if(isupper(ori[i])){
			ori[i]=tolower(ori[i]);
		}
	}
	i=0;
	while((ch=fgetc(in))!=EOF){
		if(ch!=ori[i]&&ch!=ori[i]-32&&isalpha(ori[i])&&p){
			fputc(ch,out);
		}
		else if(ch!=ori[i]&&ch!=ori[i]-32&&isalpha(ori[i])&&(!p)){
			p=1;
			t[i]=ch;
			i=0;
			fputs(t,out);
			memset(t,0,sizeof(t));
		}
		else if((ch==ori[i]||ch==ori[i]-32)&&isalpha(ori[i])){
			t[i]=ch;
			p=0;
			i++;
			if(i==len_o){
				fputs(rep,out);
				memset(t,0,sizeof(t));
				i=0;
				p=1;
			}
		}
		else if(ch!=ori[i]&&(!isalpha(ori[i]))){
			fputc(ch,out);
		}
		else if(ch!=ori[i]&&(!isalpha(ori[i]))){
			p=1;
			t[i]=ch;
			i=0;
			fputs(t,out);
			memset(t,0,sizeof(t));
		}
		else if((ch==ori[i])&&(!isalpha(ori[i]))){
			t[i]=ch;
			p=0;
			i++;
			if(i==len_o){
				fputs(rep,out);
				memset(t,0,sizeof(t));
				i=0;
				p=1;
			}
		}	
	}
	fclose(in);
	fclose(out);
	return 0;
} 
