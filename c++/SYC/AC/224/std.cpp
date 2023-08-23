#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, n, m;
ll w[10005], v[10005];
ll x;
ll dp[10005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &s, &n, &m);
    for (ll i = 1; i <= s; i++)
        scanf("%lld", &x), w[i % n == 0 ? n : i % n]++, v[i % n == 0 ? n : i % n] += x;
    // for (ll i = 1; i <= n; i++)
    //     printf("%lld %lld\n", w[i], v[i]);
    for (ll i = 1; i <= n; i++)
        for (ll j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    printf("%lld\n", dp[m]);
    return 0;
}