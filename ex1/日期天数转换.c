#include <stdio.h>
int main(void){
	int y,m,d,num=0,i;
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d",&y,&m,&d);
	if(y%4==0){
		if((y%100!=0)||((y%100==0)&&(y%400==0)))
			day[1]=29;
	}
	for(i=0;i<m-1;i++)
		num+=day[i];
	num+=d;
	printf("%d",num);
	return 0;
}
