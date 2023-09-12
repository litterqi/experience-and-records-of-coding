#include<bits/stdc++.h>
using namespace std;
int monkey[2004];
int sum[2004];
int dp[2004][2004];
int index[2004][2004];
int main()
{   
    int n,j,ans;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)//倍长数组，破环为链
        {
            cin>>monkey[i];
            monkey[n+i]=monkey[i];
        }
        for(int i=1;i<=2*n;i++)//计算前缀和
        {
            sum[i]=sum[i-1]+monkey[i];
            index[i][i]=i;//对于每一个猴子，它的最佳决策位置（即最佳k的位置）就是它自己的位置
        }    
        for(int d=2;d<=n;d++)//区间dp
        {
            for(int i=1;i<=(2*n-d);i++)
            {
                j=i+d-1;
                dp[i][j]=INT_MAX;
                for(int k=index[i][j-1];k<=index[i+1][j];k++)//四边形不等式优化
                {
                    if(dp[i][j]>(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]))
                    {
                        dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                        index[i][j]=k;
                    }
                }
            }
        }
        ans=INT_MAX;
        for(int i=1;i<=n;i++)//取区间长度为n的dp[i][j]最小值作为答案
            ans=min(ans,dp[i][i+n-1]);
        cout<<ans<<endl;    
    }
}
