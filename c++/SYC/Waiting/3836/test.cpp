#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int st[20000005], pos, p[20000005];
void fun(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            p[++pos] = i;
        for (int j = 1; j <= pos && i * p[j] <= n; j++)
        {
            st[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
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
    fun(n);
    if (k == 1)
        printf("%lld", ((1 + n) * (n / 2)) % mod), exit(0);
    for (ll i = 1; i <= n; i++)
        ans += __gcd(i, k) * qpow(i, k, mod), ans %= mod;
    printf("%lld\n", ans);
    return 0;
}