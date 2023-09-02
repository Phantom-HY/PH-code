#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m;
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
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    printf("%lld", (qpow(m, n, mod) - ((m % mod) * qpow(m - 1, n - 1, mod) % mod) + mod) % mod);
    return 0;
}