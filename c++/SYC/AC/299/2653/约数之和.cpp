#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n,x;
ll ans=1;
unordered_map<int,int>m;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for (int j=2;j<=x/j;j++)
        {
            while (x%j==0)
                x/=j,m[j]++;
        }
        if (x>1)
            m[x]++;
    }
    for (auto &&i:m)
    {
        int x=i.first,y=i.second;
        ll cnt=1;
        while(y--)
            cnt=(cnt*x+1)%MOD;
        ans=ans*cnt%MOD;
    }
    printf("%lld",ans);
    return 0;
}