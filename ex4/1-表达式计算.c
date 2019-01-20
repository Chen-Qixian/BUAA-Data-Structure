#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char cal[100000],num[100000][20],op[100000];
int val[100000];
int sum;
void del_(char x[]){
	int i,j;
	for(i=0,j=0;x[i]!='\0';i++)
		if(x[i]!=' ')
			x[j++]=x[i];
	x[j]='\0';
}

void exchange(char cal[]){
	int i,j,k,l=0,head=0,len; 
	for(i=0;i<strlen(cal);i++){
		if(cal[i]=='+'||cal[i]=='-'||cal[i]=='*'||cal[i]=='/'||cal[i]=='='){
			for(j=head,k=0;j<i;j++,k++){
					num[l][k]=cal[j];
			}
			op[l]=cal[i];
			l++;
			head=i+1;
		}
	}
	len=l;
	for(l=0;l<len;l++){
		val[l]=atoi(num[l]);
	}
}

void work(char cal[],char op[],int val[]){
	int i,temp;
	for(i=0;i<strlen(op);){
		if(op[i]=='+'||op[i]=='-'){
			if(i==0){
				sum+=val[i];
			}
			else if(i>0&&(op[i-1]=='+'||op[i-1]=='-')){
				sum+=val[i];
			}
			else if(i>0&&(op[i-1]=='*'||op[i-1]=='/')){
				sum+=temp;
			}
			if(op[i]=='-'){
				val[i+1]*=-1;
			}
			i++;
		}
		else if(op[i]=='*'||op[i]=='/'){
			temp=val[i];
			while(1){
				if(op[i]=='*'){
					temp*=val[i+1];
				}
				else if(op[i]=='/'){
					temp/=val[i+1];
				}
				else if(op[i]=='+'||op[i]=='-'||op[i]=='='){
					break;
				}
				i++;
			}
		}
		else if(op[i]=='='){
			if(i>0&&(op[i-1]=='+'||op[i-1]=='-')){
				sum+=val[i];
			}
			else if(i>0&&(op[i-1]=='*'||op[i-1]=='/')){
				sum+=temp;
			}
			else if(i==0){
				sum+=val[0];
			}
			break;
		}
	}
}
int main(void){
	gets(cal);
	del_(cal);
	exchange(cal);	
	work(cal,op,val);
	printf("%d",sum);
	return 0;
}
