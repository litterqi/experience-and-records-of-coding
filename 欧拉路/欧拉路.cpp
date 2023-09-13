#include<bits/stdc++.h>
using namespace std;
int matrix[23][23];
int degree[23];
int route[45];
int n,cnt=0;
void dfs(int p)
{
    for(int i=1;i<=n;i++)
    {
        if(matrix[p][i])
        {
            matrix[p][i]=matrix[i][p]=0;
            dfs(i);
        }
    }
    route[cnt++]=p;
}
int main()
{
    int e,x,y,start=1;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;
        matrix[x][y]=matrix[y][x]=1;
        degree[x]++;
        degree[y]++;
    }
    for(int i=n;i>=1;i--)
    {
        if(degree[i]%2)
        {
            start=i;
            break;
        }
    }
    dfs(start);
    for(int i=cnt-1;i>=0;i--)
        cout<<route[i]<<' ';
}