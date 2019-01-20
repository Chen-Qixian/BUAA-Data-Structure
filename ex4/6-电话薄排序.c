#include <stdio.h>
#include <string.h>
struct Person{
	char name[1000],num[1000];
}p[100],temp;
void del(struct Person p[],int n){
	int i;
	for(i=0;i<n;i++){
		if(strlen(p[i].name)>10){
			p[i].name[10]='\0';
		}
		if(strlen(p[i].num)>10){
			p[i].num[10]='\0';
		}
	} 
}
void quick(struct Person p[],int s,int t){
	int i,j;
	if(s<t){
		i=s;
		j=t+1;
		while(1){
			do i++;
			while(!(strcmp(p[s].name,p[i].name)<=0||i==t));
			do j--;
			while(!(strcmp(p[s].name,p[j].name)>=0||j==s));
			if(i<j){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
			else break;
		}
		temp=p[s];
		p[s]=p[j];
		p[j]=temp;
		quick(p,0,j-1);
		quick(p,j+1,t);
	}
}
int main(void){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s",p[i].name,p[i].num);
	}
	del(p,n);
	quick(p,0,n-1);
	for(i=0;i<n;i++){
		printf("%12s%12s\n",p[i].name,p[i].num);
	}
	return 0;
}
