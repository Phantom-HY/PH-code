#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans, x;
unordered_map<ll, ll> m;
ll REV(ll x)
{
    ll c = 0;
    while (x != 0)
    {
        c *= 10;
        c += x % 10;
        x /= 10;
    }
    return c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x), m[x - REV(x)]++;
    for (auto i : m)
        if (i.second >= 2)
            ans += (i.second - 1) * i.second / 2;
    printf("%lld", ans);
    return 0;
}