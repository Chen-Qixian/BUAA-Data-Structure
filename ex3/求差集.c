#include <stdio.h>
int a[100000],b[100000];
int main(void){
	int i=0,j=0,n,m,p;
	while(1){
		scanf("%d",&a[i]);
		if(a[i]==-1) break;
		i++;
	}
	n=i;
	while(1){
		scanf("%d",&b[j]);
		if(b[j]==-1) break;
		j++;
	}
	m=j;
	for(i=0;i<n;i++){
		p=1;
		for(j=0;j<m;j++){
			if(a[i]==b[j]){
				p=0;
				break;
			}
		}
		if(p){
			printf("%d ",a[i]);
		}
	}
	return 0;
}
