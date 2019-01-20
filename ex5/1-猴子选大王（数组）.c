#include <stdio.h>
int b[1000] = {0};
int main(void){
	int n,m,q,i,p,p0;
	scanf("%d %d %d",&n,&m,&q);
	q--;
	for(i=0;i<n-1;i++){
		p=1;
		p0=1;
		while(p0){
			if(!b[q]){
				p++;
				q++;
				q%=n;
			}
			else{
				q++;
				q%=n;
			}
			if(p==m){
				while(1){
					if(b[q]){
						q++;
						q%=n;
					}
					else break;
				}
				b[q]=1;
				p0=0;
			}
		}
	}
	while(1){
		if(b[q]){
			q++;
			q%=n;
		}
		else{
			break;
		}
	}
	printf("%d",q+1);
	return 0;
} 
