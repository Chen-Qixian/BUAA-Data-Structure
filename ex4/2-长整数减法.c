#include <stdio.h>
#include <string.h>
char a[100],b[100];
void del_0(char a[]){
	int i,j,p=1;
	for(i=j=0;a[i]!='\0';i++){
		if(a[i]!='0'&&p){
			p=0;
		}
		if(!p){
			a[j++]=a[i];
		}
	}
	a[j]='\0';
}
void change(char p[],int len){
	char t[100];
	int i,j;
	for(i=len-1,j=strlen(p)-1;i>=0;i--,j--){
		if(j>=0){
			t[i]=p[j];
		}
		else{
			t[i]='0';
		}
	}
	for(i=0;i<len;i++){
		p[i]=t[i];
	}
}
void minus(char x[],char y[]){
	int len=strlen(x),i;
	change(y,len);
	for(i=len-1;i>=0;i--){
		if(x[i]>=y[i]){
			x[i]='0'+x[i]-y[i];
		}
		else{
			x[i-1]--;
			x[i]='0'+10+x[i]-y[i];
		}
	}
}
int main(void){
	scanf("%s",a);
	scanf("%s",b);
	del_0(a);
	del_0(b);
	int l_a=strlen(a),l_b=strlen(b);
	if(l_a>l_b||(l_a==l_b&&strcmp(a,b)>0)){
		minus(a,b);
		del_0(a);
		printf("%s\n",a);
	}
	else if(l_a<l_b||(l_a==l_b&&strcmp(a,b)<0)){
		minus(b,a);
		del_0(b);
		printf("-%s\n",b);
	}
	else printf("0");
	return 0;
}
