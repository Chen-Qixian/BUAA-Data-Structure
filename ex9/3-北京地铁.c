#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INFI 32767
#define MAXS 512
#define MAXN 20

/*Project ID : 9-3
  Project Name : Beijing Subway Line Query
  Author : Chen_Qixian
  Latest Update : July.2nd,2017
  Version : BSLQ3.0 
*/

struct  VERT{
	char name[MAXN];
	int change;
}station[MAXS];

struct WEIGHT{
	int lnum;
	int wei;
}weight[MAXS][MAXS];

int v0,vn,vnum,spath[MAXS];

void getmap(void){
	FILE *in;
	int i,j,k=0,l,p,v1,v2,total,line_num,sta_num;
	in=fopen("bgstations.txt","r");
	fscanf(in,"%d",&total);
	for(i=0;i<total;i++){
		fscanf(in,"%d %d",&line_num,&sta_num);
		v1=v2=-1;
		for(j=0;j<sta_num;j++){
			p=1;
			fscanf(in,"%s %d",station[k].name,&station[k].change);
			if(station[k].change){
				for(l=0;l<k;l++){
					if(strcmp(station[l].name,station[k].name)==0){
						v2=l;
						p=0;
						break;
					}
				}
				if(p){
					v2=k;
					k++;
				}
			}
			else{
				v2=k;
				k++;
			}
			if(v1!=-1){
				weight[v1][v2].wei=weight[v2][v1].wei=1;
				weight[v1][v2].lnum=weight[v2][v1].lnum=line_num;
			}
			v1=v2;
		}	
	}
	vnum=k;
	for(i=0;i<vnum;i++){
		for(j=0;j<vnum;j++){
			if(weight[i][j].wei!=1){
				weight[i][j].wei=INFI;
			}
		}
	}
	fclose(in);
}

void getv0vn(void){
	int i;
	char depart[MAXN],dest[MAXN];
	printf("欢迎使用北京地铁线路查询系统\n\n");
	printf("**请输入您的出发地和目的地\n\n");
	printf("出发地："); 
	scanf("%s",depart);
	printf("\n目的地：");
	scanf("%s",dest);
	for(i=0;i<vnum;i++){
		if(strcmp(depart,station[i].name)==0){
			v0=i;
		}
		else if(strcmp(dest,station[i].name)==0){
			vn=i;
		}
	}
}

void Dijkstra(void){
	int i,j,v=0,mweight,sweight[MAXS]={0},nfound[MAXS]={0};
	for(i=0;i<vnum;i++){
		sweight[i]=weight[v0][i].wei;
		spath[i]=v0;
	}
	nfound[v0]=1;
	sweight[v0]=0;
	for(i=0;i<vnum-1;i++){
		mweight=INFI;
		for(j=0;j<vnum;j++){
			if(!nfound[j]&&(sweight[j]<mweight)){
				v=j;
				mweight=sweight[j];
			}
		}
		nfound[v]=1;
		if(v==vn) return;
		for(j=0;j<vnum;j++){
			if(!nfound[j]&&(weight[v][j].lnum>0)&&mweight+weight[v][j].wei<sweight[j]){
				sweight[j]=mweight+weight[v][j].wei;
				spath[j]=v;
			}
		}
	}
}

void output(void){
	int que[200],cnt=0,line=-1,lcnt=1,i;
	do{
		que[cnt++]=vn;	
	}while((vn=spath[vn])!=v0);
	que[cnt++]=v0;
	line=weight[que[cnt-1]][que[cnt-2]].lnum;
	printf("\n从%s出发，乘坐%d号线，",station[que[cnt-1]].name,line);
	lcnt=1;
	for(i=cnt-2;i>0;i--,lcnt++){
		if(weight[que[i]][que[i-1]].lnum!=line){
			line=weight[que[i]][que[i-1]].lnum;
			printf("经过%d站，到达%s\n\n换乘%d号线，",lcnt,station[que[i]].name,line);
			lcnt=0;	
		}
	}
	printf("再经过%d站后，到达终点：%s\n\n",lcnt,station[que[i]].name);
}

int main(void){
	getmap();
	getv0vn();
	Dijkstra();
	output();
	return 0;
}
