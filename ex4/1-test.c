#include <stdio.h>
#include <string.h>
int sum=0;
int main(void){
	char  op[]="-**+//=";
	int val[]={5,1,2,3,12,2,2};
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
			printf("val%d:%d\n",i+1,val[i+1]);
			printf("sum:%d\n",sum);
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
					printf("sum:%d\n",sum);
					break;
				}
				printf("temp:%d\n",temp);
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
	printf("%d",sum);
	return 0;
}
