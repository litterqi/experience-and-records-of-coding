#include<bits/stdc++.h>
using namespace std;
int a[105];
int pre[105];//前缀和数组
set<pair<int,int>> v[105];//v[i]表示对于a[1]~a[i],可以形成的所有最小值--最大值的情况  
//易证,最小值为x,最大值为y的情况一定比最小值为x'(x'<=x),最大值为y'(y'>=y)好，我们定义这种包含的情况为更优秀
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];//计算前缀和
    }
    v[2].insert({min(a[1],a[2]),max(a[1],a[2])});//对于第二位及以前的数，只有一种选择方法，即不合并第一第二个数
    for(int i=3;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            int newsum=pre[i]-pre[j];
            //新加进元素i归入j+1~i的区间,尝试将其和原先1~j可能形成的最小--最大值组合合并成更优秀的区间，newsum表示j+1~i区间的和
            for(auto p:v[j])
            {
                set<pair<int,int>> erasest;
                pair<int,int> np={min(newsum,p.first),max(newsum,p.second)};//合并成的新最小--最大值
                bool judge=true;//判断是否形成可能更优的新最小--最大值情况
                for(auto k:v[i]) 
                {
                    if (np.first >= k.first && np.second <= k.second &&np != k)    
                    {
                        //若新最小--最大值包含了旧的某个最小--最大值k，则删除k，此处把k加入待删除的元素集合
                        erasest.insert(k);
                    } 
                    else if (np.first <= k.first && np.second >= k.second) 
                    {
                        //若新最小--最大值被旧的某个最小--最大值k包含，则意味着新最小--最大值无用，直接退出循环
                        judge = false;
                        break;
                    }
                }
                if(judge)
                    v[i].insert(np);
                else
                {   
                    for(auto k:erasest)
                        v[i].erase(k);
                }   
            }
            //最后尝试将1~j合并为一个新区间与j+1~i一起形成一个最小--最大值组合，判断是否更优秀的方法同上
            set<pair<int,int>> erasest;
            pair<int,int> np={min(newsum,pre[j]),max(newsum,pre[j])};
            bool judge=true;
            for(auto k:v[i]) 
            {
                if (np.first >= k.first && np.second <= k.second&&np!=k) 
                    erasest.insert(k);
                else if (np.first <= k.first && np.second >= k.second) 
                {
                    judge = false;
                    break;
                }
            }
            for(auto k:erasest)
                v[i].erase(k);
            if(judge)
                v[i].insert(np);
        }
    }
    int ans=-1;
    for(auto p:v[n])
    {
        //在所有1~n的最小最大值组合中算出最小的方法值
        if(ans==-1||ans>p.second-p.first)
            ans=p.second-p.first;
    }
    cout<<ans;    
}