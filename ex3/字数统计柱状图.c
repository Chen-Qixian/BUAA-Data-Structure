#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int a[30]={0};
int n,i,k;
char s[10000];
char c;
int main(void){
	int max(int a[30]);
	while(scanf("%s",s)!=EOF){
		for(i=0;i<strlen(s);i++){
			if(islower(s[i]))
				a[s[i]-97]++;
		}
	}
	n=max(a);
	for(i=0;i<n;i++){
		for(k=0;k<26;k++){
			if(n-a[k]>i){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	for(i=0;i<26;i++){
		c='a'+i;
		printf("%c",c);
	}
	return 0;
}
int max(int a[30]){
	int j,max=a[0];
	for(j=1;j<26;j++){
		max=(a[j]>max)?a[j]:max;
	}
	return max;
} 
