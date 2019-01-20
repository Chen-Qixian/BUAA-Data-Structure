#include <stdio.h>
#include <stdlib.h>

int k[300];
int n,cnt=0;

void select_sort(){
	int i,j,min,t;
	for(i=1;i<=n;i++){
		min=i;
		for(j=i+1;j<=n;j++){
			if(k[j]<k[min]){
				min=j;
			}
			cnt++;
		}
		t=k[i];
		k[i]=k[min];
		k[min]=t;
	}
}

void pop_sort(){
	int i,j,t,p=1;
	for(i=n;i>1&&p;i--){
		p=0;
		for(j=1;j<i;j++){
			if(k[j]>k[j+1]){
				t=k[j];
				k[j]=k[j+1];
				k[j+1]=t;
				p=1;
			}
			cnt++;
		}
	}
}

void adjust(int i,int n0){
	int j=i*2,temp=k[i];
	while(j<=n0){
		if(k[j]<k[j+1]&&j<=n0-1){
			j++;
		}
		if(temp>=k[j]){
			cnt++;
			break;
		}
		cnt++;
		k[j/2]=k[j];
		j*=2;
	}
	k[j/2]=temp;
}

void heap_sort(){
	int i,t;
	for(i=n/2;i>0;i--){
		adjust(i,n);
	}
	for(i=n-1;i>0;i--){
		t=k[i+1];
		k[i+1]=k[1];
		k[1]=t;
		adjust(1,i);
	}
}

void merge(int kk[],int tmp[],int left,int leftend,int rightend){
	int i,j,q;
	i=left;
	j=leftend+1;
	q=left;
	while(i<=leftend&&j<=rightend){
		cnt++;
		if(kk[i]<kk[j]){
			tmp[q++]=kk[i++];
		}
		else{
			tmp[q++]=kk[j++];
		}
	}
	while(i<=leftend){
		tmp[q++]=kk[i++];
	}
	while(j<=rightend){
		tmp[q++]=kk[j++];
	}
	for(i=left;i<=rightend;i++){
		kk[i]=tmp[i];
	}
}

void msort(int kk[],int tmp[],int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
		msort(kk,tmp,left,mid);
		msort(kk,tmp,mid+1,right);
		merge(kk,tmp,left,mid,right);
	}
}

void merge_sort(int kk[],int n){
	int *tmp;
	tmp=(int*)malloc(sizeof(int)*n);
	msort(kk,tmp,1,n);
	free(tmp);
}

void quick_sort(int left,int right){
	int i,t,last;
	if(left<right){
		last=left;
		for(i=left+1;i<=right;i++){
			if(k[i]<k[left]){
				last++;
				t=k[i];
				k[i]=k[last];
				k[last]=t;
			}
			cnt++;
		}
		t=k[last];
		k[last]=k[left];
		k[left]=t;
		quick_sort(left,last-1);
		quick_sort(last+1,right);
	}
}

int main(void){
	int i,op;
	scanf("%d %d",&n,&op);
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
	} 
	if(op==1) select_sort();
	else if(op==2) pop_sort();
	else if(op==3) heap_sort();
	else if(op==4) merge_sort(k,n);
	else if(op==5) quick_sort(1,n);
	for(i=1;i<=n;i++){
		printf("%d ",k[i]);
	}
	printf("\n%d",cnt);
	return 0;
}
