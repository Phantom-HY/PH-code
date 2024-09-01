#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n, k;
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
ll ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &k);
    if (k == 1)
        printf("%lld", ((1 + n) * (n / 2)) % mod), exit(0);
    for (ll i = 1; i <= n; i++)
        ans += __gcd(i, k) * qpow(i, k, mod), ans %= mod;
    printf("%lld\n", ans);
    return 0;
}