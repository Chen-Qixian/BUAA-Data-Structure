#include <stdio.h>
//��̬�滮�㷨 
char s[10010];
int temp,dp[10010],i,j,max;     //dp[i]Ϊ�Ե�iԪ��Ϊ���һλ������г��� 
int main(void){
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){    //��ʼ����ÿһԪ��Ϊ���Ҷ˵����г���Ϊ1 
		dp[i]=1;
	}
	for(i=0;s[i]!='\0';i++){
		temp=1;
		for(j=0;j<i;j++){
			if(s[i]>=s[j]){            //�ڴ�Ԫ��֮ǰ��С�ڸ�Ԫ��Ԫ�� 
				if(dp[i]+dp[j]>temp){
					temp=dp[i]+dp[j];   //�����Ϊ�ȸ�ԪС����һԪ����г���+1 
				}
			}
		}
		dp[i]=temp;                    //���¸�Ԫ�ص�����г��� 
	}
	max=dp[0];
	for(i=0;s[i]!='\0';i++){            //Ѱ��dp�е�max 
		if(dp[i]>max){
			max=dp[i];
		}
	}
	printf("%d\n",max);
	return 0;
} 
