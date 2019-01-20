#include <stdio.h>
#include <stdlib.h>
int k[300]={0,13,25,24,86,43,64,25,15,78,54};
int n;

void merge(int x[],int tmp[],int left,int leftend,int rightend){     
       int i=left,j=leftend+1,q=left;
       while(i<=leftend&&j<=rightend){
			if(x[i]<=x[j])                                 //按题意，此处附近应该有计数判断，自己考虑一下 
                tmp[q++]=x[i++];                      //将两个按序书数组合并 
            else
                tmp[q++]=x[j++];
       }
       while(i<=leftend)
    		tmp[q++]=x[i++];
       while(j<=rightend)
            tmp[q++]=x[j++];
       for(i=left;i<=rightend;i++)
            x[i]=tmp[i];
}


void mSort(int kk[],int tmp[],int left,int right){ 
    int center;
    if(left<right){                                      //判断条件：最后一次递归结束已将数组分为单位长度为2的数组 
        center=(left+right)/2;                        //递归过程，每次都是原来的一半 
        mSort(kk,tmp,left,center);                      //left,right的意思是每次处理的数组的首尾 
        mSort(kk,tmp,center+1,right);                   
        merge(kk,tmp,left,center,right);                
    }
}

void mergeSort(int kk[],int n){                 
    int tmp[100]; 
    mSort(kk,tmp,1,n);
}


int main(void){
	int i;
	n=10;
	mergeSort(k,n);
	for(i=1;i<=n;i++){
		printf("%d ",k[i]);
	}
	return 0;
}
