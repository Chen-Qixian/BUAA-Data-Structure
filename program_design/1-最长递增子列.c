#include <stdio.h>
//动态规划算法 
char s[10010];
int temp,dp[10010],i,j,max;     //dp[i]为以第i元素为最后一位的最长子列长度 
int main(void){
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){    //初始化以每一元素为最右端的子列长度为1 
		dp[i]=1;
	}
	for(i=0;s[i]!='\0';i++){
		temp=1;
		for(j=0;j<i;j++){
			if(s[i]>=s[j]){            //在此元素之前有小于该元的元素 
				if(dp[i]+dp[j]>temp){
					temp=dp[i]+dp[j];   //最长长度为比该元小的那一元最长子列长度+1 
				}
			}
		}
		dp[i]=temp;                    //更新该元素的最长子列长度 
	}
	max=dp[0];
	for(i=0;s[i]!='\0';i++){            //寻求dp中的max 
		if(dp[i]>max){
			max=dp[i];
		}
	}
	printf("%d\n",max);
	return 0;
} 
