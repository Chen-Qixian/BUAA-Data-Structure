#include <stdlib.h>  
#include <stdio.h>  
int cnt=0;
//�������X[s..u]��X[u+1..v]�鲢Ϊ�����Z[s..v]  
void merge(int X[], int Z[], int s, int u, int v)  
{  
    int i, j, q;  
    i = s;  
    j = u + 1;  
    q = s;  
  
    while( i <= u && j<= v )  
    {  
        if( X[i] <= X[j] ){
			Z[q++] = X[i++];
			cnt++;
        }                
        else{
			Z[q++] = X[j++];
			cnt++;
        }       
    }  
  
    while( i <= u )   //��X��ʣ��Ԫ��X[i..u]���Ƶ�Z  
        Z[q++] = X[i++];  
    while( j <= v )   //��X��ʣ��Ԫ��X[j..v]���Ƶ�Z  
        Z[q++] = X[j++];  
}  
  
/* X[0..n-1]��ʾ�μ�����ĳ�ʼ���� 
 * tΪĳһ�˹鲢ʱ�����еĳ��� 
 * ���ͱ���iָ����ǰ�鲢�������������е�1�������еĵ�1��Ԫ�ص�λ�� 
 * Y[0..n-1]��ʾ��һ�˹鲢��Ľ�� 
*/  
void mergePass(int X[], int Y[], int n, int t)  
{  
    int i = 0, j;  
    while( n - i >= 2 * t )     //�����ڵ���������Ϊt�ĸ�������������кϲ���һ������Ϊ2t��������  
    {  
        merge(X, Y, i, i + t - 1, i + 2 * t - 1);  
        i = i + 2 * t;  
    }  
  
    if( n - i > t )       //�����ʣ�µ�Ԫ�ظ�������һ�������еĳ���tʱ  
        merge(X, Y, i, i + t - 1, n - 1);  
    else             //n-i <= tʱ���൱��ֻ�ǰ�X[i..n-1]�����е����ݸ�ֵ��Y[i..n-1]  
        for( j = i ; j < n ; ++j )  
            Y[j] = X[j];  
}  
  
void mergeSort(int X[], int n)  
{  
    int t = 1;  
    int *Y = (int *)malloc(sizeof(int) * n);  
    while( t < n )  
    {  
        mergePass(X, Y, n, t);  
        t *= 2;  
        mergePass(Y, X, n, t);  
        t *= 2;  
    }  
    free(Y);  
}  
  
void print_array(int array[], int n)  
{  
    int i;  
    for( i = 0 ; i < n ; ++i )  
        printf("%d ", array[i]);  
    printf("\n"); 
	printf("%d",cnt); 
}  
  
int main()  
{  
    int array[] = {38,356,98,-102,126,46,65,-9,100,0,21,2,90,8,18,12,78,16,189,23};  
    int size = sizeof(array) / sizeof(int);  
    mergeSort(array, size);  
    print_array(array, size);  
    return 0;  
}  
