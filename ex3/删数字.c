#include <stdio.h>
#define Len(s) (sizeof(s)/sizeof(s[0]))
char s[300];
int n,i,j,k;
int main(void){	
	scanf("%s",s);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<Len(s);j++){
			if(s[j]>s[j+1]){
				for(k=j;k<Len(s);k++){
					s[k]=s[k+1];
				}
				break;
			}
		}
	}
	printf("%s",s);
	return 0;
} 
