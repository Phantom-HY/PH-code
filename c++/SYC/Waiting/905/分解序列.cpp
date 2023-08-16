#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r;
bitset<1000000000>s;
ll len;
void dfs(ll x)
{
    if (x<2)
    {
        s[++len]=x;
        return ;
    }
    dfs(x/2);
    s[++len]=x%2;
    if (len>=r)
    {
        int ans=0;
        for (ll i=l;i<=r;i++)
            ans+=s[i];
        printf("%d\n",ans);
        exit(0);
    }
    ll llen=len-1;
    for (ll i=1;i<=llen;i++)
        s[++len]=s[llen];
    if (len>=r)
    {
        int ans=0;
        for (ll i=l;i<=r;i++)
            ans+=s[i];
        printf("%d\n",ans);
        exit(0);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld",&n,&l,&r);
    dfs(n);
    return 0;
}