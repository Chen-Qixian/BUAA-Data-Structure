#include <stdio.h>
int a[1000][1000]={{0}};
int n,i,j,x;
char o='+';
int main(void){
	scanf("%d",&n);
	while(o!='#'){
		if(o=='+'){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					scanf("%d",&x);
					a[i][j]+=x;
				}
			}
		}
		else if(o=='-'){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					scanf("%d",&x);
					a[i][j]-=x;
				}
			}
		}
		scanf("%c",&o);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
