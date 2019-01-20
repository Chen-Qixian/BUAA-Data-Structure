#include <stdio.h>
int main(void){
	double e,pi0,pi1,fz,fm;
	int n=3,i,boolp=1;
	scanf("%lf",&e);
	pi0=2;
	pi1=2*(1+(double)1/3);
	//printf("%lf\n",pi1);
	if(e>=pi1-pi0){
		printf("%d %.7lf",n-1,pi1);
		boolp=0;
	} 
	while(pi1-pi0>=e){
		fz=fm=1;
		pi0=pi1;
		for(i=2;i<=n;i++){
			fz*=i-1;
			fm=fm*(2*i-1);			
		}
		pi1+=2*fz/fm;
		//printf("%.7lf %.7lf\n",pi0,pi1);
		n++;
		//printf("%d\n",n);
	}
	if(boolp)
		printf("%d %.7lf",n-1,pi1);
	return 0;
}
