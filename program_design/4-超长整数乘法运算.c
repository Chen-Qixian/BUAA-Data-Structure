#include <stdio.h>
#include <string.h>
char a[200],b[200],sum[300];
char t[200][300];
void set_0(){
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<200;j++){
			t[i][j]='0';
		}
		t[i][j]='\0';
	}
	for(i=0;i<200;i++){
		sum[i]='0';
	}
}
void reverse(char x[]){
	int i,temp,n=strlen(x);
	for(i=0;i<n/2;i++){
		temp=x[i];
		x[i]=x[n-1-i];
		x[n-1-i]=temp;
	}
}
void vertical(){
	int i,j,k,l;
	for(i=0;b[i]!='\0';i++){
		for(j=0;a[j]!='\0';j++){
			t[i][j+1]+=((a[j]-'0')*(b[i]-'0')+t[i][j]-'0')/10;
			t[i][j]=(((a[j]-'0')*(b[i]-'0'))%10+t[i][j]-'0')%10+'0';			
		}
		if(t[i][j]!='0'){
			j++;
		}
		for(k=0;k<i;k++,j++){
			l=j;
			while(l>k){
				t[i][l]=t[i][l-1];
				l--;
			}
			t[i][k]='0';
		}
	}
}
void add(char sum[],char t[]){
	int i;
	for(i=0;i<200;i++){
		sum[i+1]+=(sum[i]+t[i]-'0'-'0')/10;
		sum[i]=(sum[i]-'0'+t[i]-'0')%10+'0';
	}
}
void del_0(char sum[]){
	int i,j,p=1;
	for(i=j=0;sum[i]!='\0';i++){
		if(sum[i]!='0'){
			p=0;
		}
		if(!p){
			sum[j++]=sum[i];
		}
	}
	if(p){
		sum[0]='0';
		sum[1]='\0';
	}
	else sum[j]='\0';
}
int main(void){
	int i;
	scanf("%s",a);
	scanf("%s",b);
	set_0();
	reverse(a);
	reverse(b);
	vertical();
	for(i=0;i<strlen(b);i++){
		add(sum,t[i]);
	}
	reverse(sum);
	del_0(sum);
	puts(sum);
	return 0;
} 
