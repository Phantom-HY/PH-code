#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[1300005],d[20000005]={0,1};
ll n,a,m;
ll ans;
char cnt[20000005];
bitset<20000005>f;
void D(int n)
{
    int s=0;
    for (int i=2;i<=n;i++)
    {
        if(!f[i])
        {
            p[s++]=i;
            cnt[i]=1;
            d[i]=2;
        }
        for (ll j=0;j<s&&i*p[j]<=n;j++)
        {
            f[i*p[j]]=1;
            if (i%p[j])
            {
                d[i*p[j]]=2*d[i];
                cnt[i*p[j]]=1;
            }else {
                d[i*p[j]]=d[i]/(cnt[i]+1)*(cnt[i]+2);
                cnt[i*p[j]]=cnt[i]+1;
                break;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &n, &a, &m);
    D(n);
    for (int i = 1, k = -1; i <= n; i++, k *= -1)
    {
        ans += d[i] * ((k * (i + a)) % m);
    }
    printf("%lld", ans);
    return 0;
}