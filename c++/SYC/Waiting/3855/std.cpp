#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l,r,m,p;
ll fun(int i,int k)
{
    ll ans = 1;
    for (int  j = i-k+1;j<=i;j++)
        ans*=j,ans%=p;
    return ans;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d",&l,&r,&m,&p);
    ll ans = 0;
    for (int i = l;i<=r;i++)
        ans+=fun(i,m),ans%=mod;
    printf("%lld\n",ans);
    return 0;
}