#include <stdio.h>
int wait[10000]={0},que[10000]={0},cus[2000]={0};
int i,j=1,k,n=0,T,total=0,win=3,head=1,dis=0;
int main(void){
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d",&cus[i]);
		n+=cus[i];
	}
	for(i=1;;i++){
		total+=cus[i];
		if(cus[i]!=0){
			for(k=0;k<cus[i];k++){
				que[j++]=1;
			}
			if(total/win>=7&&win<5){
				if(total/(win+1)<7){
					win++;
				}
				else if(total/(win+1)>=7&&win==3){
					win+=2;
				}
				else if(total/(win+1)>=7&&win==4){
					win++;
				}
			}
		}
		total=total-win;
		if(total>0){
			for(k=0;k<win;k++){
				que[head++]=0;
			}
			dis+=win;
		}
		else{
			for(k=0;k<total+win;k++){
				que[head++]=0;
			}
			dis=dis+total+win;
			total=0;
		}
		if(total/win<7&&win>3){
			win--;
		}
		for(k=1;k<=n;k++){
			if(que[k]==1){
				wait[k]++;
			}
		}		
		if(dis==n){
			break;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d : %d\n",i,wait[i]);
	}
	return 0;
}
