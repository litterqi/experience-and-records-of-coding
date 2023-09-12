#include<bits/stdc++.h>
using namespace std;
int weight[505];
int value[505];
int dp[10005];
int main()
{
    int t,n,e,f,v;
    cin>>t;
    for(int op=0;op<t;op++)
    {
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        cin>>e>>f>>n;
        v=f-e;
        for(int i=1;i<=n;i++)
        {
            cin>>value[i]>>weight[i]; 
            for(int j=weight[i];j<=v;j++)
                dp[j]=min(dp[j],dp[j-weight[i]]+value[i]);   
        }  
        if(dp[v]==0x3f3f3f3f)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[v]<<'.'<<endl;    
    }
}
