#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,n;
ll qpow(ll a, ll b, ll MOD)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld",&a,&n);
    printf("%lld",(qpow(a,n+1,1000000007)-1+1000000007)%1000000007);
    return 0;
}