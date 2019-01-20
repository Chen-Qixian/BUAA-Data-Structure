#include <stdio.h>
//这道题查出重复很正常，我记得上学期第二课堂上学长当例题讲过这道题。 
int p[10],flag[10]={0};
int n;
void full_permutation(int k){
	int i;
	if(k==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",p[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(!flag[i]){
			p[k]=i;
			flag[i]=1;
			full_permutation(k+1);
			flag[i]=0;
		}
	}
}
int main(void){
	scanf("%d",&n);
	full_permutation(1);
	return 0;
} 
