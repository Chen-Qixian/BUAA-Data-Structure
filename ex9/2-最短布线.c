#include <stdio.h>
#define MAX 1024
#define INFINITE 32767

int n,e,weight[MAX][MAX]={{0}},minwei[MAX],edge[MAX],id[MAX][MAX]={{0}},len=0,add[MAX]; 

void get(void){
	int i,j,ID,vi,vj,wei;
	scanf("%d %d",&n,&e);
	for(i=0;i<e;i++){
		scanf("%d %d %d %d",&ID,&vi,&vj,&wei);
		weight[vi][vj]=wei;
		weight[vj][vi]=wei;
		id[vi][vj]=ID;
		id[vj][vi]=ID;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(weight[i][j]==0){
				weight[i][j]=INFINITE;
			}
		}
	}
}

void prim(void){
	int i,j,k,min;
	for(i=0;i<n;i++){
		minwei[i]=weight[0][i];
		edge[i]=0;
	}
	minwei[0]=0;
	for(i=0;i<n-1;i++){
		min=INFINITE;
		for(j=0,k=0;j<n;j++){
			if(minwei[j]!=0&&minwei[j]<min){
				min=minwei[j];
				k=j;
			}
		}
		minwei[k]=0;
		for(j=0;j<n;j++){
			if(minwei[j]!=0&&weight[k][j]<minwei[j]){
				minwei[j]=weight[k][j];
				edge[j]=k;
			}
		}
	}
}

void cal(void){
	int i,j,t;
	for(i=1;i<n;i++){
		len+=weight[i][edge[i]];
		add[i]=id[i][edge[i]];		
	}
	printf("%d\n",len);
	for(i=1;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(add[j]<add[j-1]){
				t=add[j];
				add[j]=add[j-1];
				add[j-1]=t;
			}
		}
	}
	for(i=1;i<n;i++){
		printf("%d ",add[i]);
	}
}

int main(void){
	get();
	prim();
	cal();
	return 0;
}
