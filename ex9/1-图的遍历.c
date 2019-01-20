#include <stdio.h>
#include <stdlib.h>
#define MaxV 10000

typedef struct Ver{
	int vert;
	struct Ver *link;
}ver,*vptr;

vptr p,q,r;
ver g[MaxV]; 
int v,e,del;
int visited[MaxV]={0},Q[MaxV];

void save_(void){
	int i,vi,vj;
	scanf("%d %d",&v,&e);
	for(i=0;i<v;i++){
		g[i].vert=i;
		g[i].link=NULL;
	}
	for(i=0;i<e;i++){
		scanf("%d %d",&vi,&vj);
		p=(vptr)malloc(sizeof(ver));
		p->link=NULL;
		p->vert=vj;
		if(g[vi].link==NULL){
			g[vi].link=p;
		}
		else{
			q=g[vi].link;
			r=&g[vi];
			while(q!=NULL){
				if(q->vert<p->vert){
					r=q;
					q=q->link;
				}
				else{
					r->link=p;
					p->link=q;
					break;
				}
			}
			if(q==NULL){
				r->link=p;
			}
		}
		p=(vptr)malloc(sizeof(ver));
		p->link=NULL;
		p->vert=vi;
		if(g[vj].link==NULL){
			g[vj].link=p;
		}
		else{
			q=g[vj].link;
			r=&g[vj];
			while(q!=NULL){
				if(q->vert<p->vert){
					r=q;
					q=q->link;
				}
				else{
					r->link=p;
					p->link=q;
					break;
				}
			}
			if(q==NULL){
				r->link=p;
			}
		}
	}
	scanf("%d",&del);	
}

void DFS(int v0){
	vptr p0;
	visited[v0]=1;
	printf("%d ",v0);
	for(p0=g[v0].link;p0!=NULL;p0=p0->link){
		if(!visited[p0->vert]){
			DFS(p0->vert);
		}
	}
}

void travelDFS(void){
	int i;
	for(i=0;i<v;i++) visited[i]=0;
	for(i=0;i<v;i++){
		if(!visited[i]){
			DFS(i);
		}
	}
}

void BFS(int v1){
	int head=0,rear=-1;
	vptr s;
	visited[v1]=1;
	printf("%d ",v1);
	Q[++rear]=v1;
	while(head<=rear){
		v1=Q[head++];
		s=g[v1].link;
		while(s!=NULL){
			if(!visited[s->vert]){
				visited[s->vert]=1;
				printf("%d ",s->vert);
				Q[++rear]=s->vert;
			}
			s=s->link;
		}
	}
}

void travelBFS(void){
	int i;
	for(i=0;i<v;i++) visited[i]=0;
	for(i=0;i<v;i++){
		if(!visited[i]){
			BFS(i);
		}
	}
}

void del_(void){
	
	int i;
	vptr p2,r2=NULL;
	for(i=0;i<v;i++){
		if(i!=del){
			for(p2=&g[i];p2!=NULL;p2=p2->link){
				if(p2->vert==del){
					r2->link=p2->link;
				}
				else{
					r2=p2;
				}
			}
		}	
	}
}

void TravelDFS(void){
	int i;
	for(i=0;i<v;i++) visited[i]=0;
	for(i=0;i<v;i++){
		if(i!=del)
			if(!visited[i]){
				DFS(i);
			}
	}
}

void TravelBFS(void){
	int i;
	for(i=0;i<v;i++) visited[i]=0;
	for(i=0;i<v;i++){
		if(i!=del)
			if(!visited[i]){
				BFS(i);
			}
	}
}

int main(void){
	save_();
	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	del_();
	TravelDFS();
	printf("\n");
	TravelBFS();
	return 0;
}
