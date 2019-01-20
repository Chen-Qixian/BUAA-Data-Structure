#include <stdlib.h>  
#include <stdio.h>  
int cnt=0;
//将有序的X[s..u]和X[u+1..v]归并为有序的Z[s..v]  
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
  
    while( i <= u )   //将X中剩余元素X[i..u]复制到Z  
        Z[q++] = X[i++];  
    while( j <= v )   //将X中剩余元素X[j..v]复制到Z  
        Z[q++] = X[j++];  
}  
  
/* X[0..n-1]表示参加排序的初始序列 
 * t为某一趟归并时子序列的长度 
 * 整型变量i指出当前归并的两个子序列中第1个子序列的第1个元素的位置 
 * Y[0..n-1]表示这一趟归并后的结果 
*/  
void mergePass(int X[], int Y[], int n, int t)  
{  
    int i = 0, j;  
    while( n - i >= 2 * t )     //将相邻的两个长度为t的各自有序的子序列合并成一个长度为2t的子序列  
    {  
        merge(X, Y, i, i + t - 1, i + 2 * t - 1);  
        i = i + 2 * t;  
    }  
  
    if( n - i > t )       //若最后剩下的元素个数大于一个子序列的长度t时  
        merge(X, Y, i, i + t - 1, n - 1);  
    else             //n-i <= t时，相当于只是把X[i..n-1]序列中的数据赋值给Y[i..n-1]  
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
