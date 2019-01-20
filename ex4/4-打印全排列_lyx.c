#include<stdio.h>
#include<string.h>
int a[100];
int flag[100];
int i,j,k,n,m;
void dfs(int v)
{
    int i;
    if(v==n+1)
    {
        for(i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
           a[v]=i;
           flag[i]=1;
           dfs(v+1);
           flag[i]=0;
        }
    }
}
int main()
{
  // memset(flag,0,sizeof(flag));
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
       flag[i]=1;
       a[1]=i;
       dfs(2);
       flag[i]=0;
   }
   return 0; 
}
