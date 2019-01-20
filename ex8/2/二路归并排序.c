#include <stdio.h>
#include <stdlib.h>
int k[300]={0,13,25,24,86,43,64,25,15,78,54};
int n;

void merge(int x[],int tmp[],int left,int leftend,int rightend){     
       int i=left,j=leftend+1,q=left;
       while(i<=leftend&&j<=rightend){
			if(x[i]<=x[j])                                 //�����⣬�˴�����Ӧ���м����жϣ��Լ�����һ�� 
                tmp[q++]=x[i++];                      //����������������ϲ� 
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
    if(left<right){                                      //�ж����������һ�εݹ�����ѽ������Ϊ��λ����Ϊ2������ 
        center=(left+right)/2;                        //�ݹ���̣�ÿ�ζ���ԭ����һ�� 
        mSort(kk,tmp,left,center);                      //left,right����˼��ÿ�δ�����������β 
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
