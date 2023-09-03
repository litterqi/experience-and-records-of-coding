#include<bits/stdc++.h>
using namespace std;
int good[12];
int main()
{
    int t,n,a,tmp,pack1,pack2,flag;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        flag=0;
        cin>>n;
        a=(1<<n)-1;
        for(int j=0;j<n;j++)
            cin>>good[j];
        for(int j=1;j<a;j++)
        {
            s="";
            pack1=pack2=0;
            tmp=j;
            for(int k=0;k<n;k++)
            {
                if(tmp&1)
                {
                    pack1^=good[k];
                    s+='0';
                }
                else
                {
                    pack2^=good[k];
                    s+='1';
                }
                tmp>>=1;        
            }
            if(pack1==pack2)
            {
                cout<<"Yes"<<endl<<s<<endl;
                flag=1;
                break;
            }
        }
        if(!flag) 
            cout<<"No"<<endl;
    }
}