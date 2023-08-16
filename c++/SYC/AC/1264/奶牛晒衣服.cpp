#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a, b;
int v[500005];
bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] <= a * x)
            continue;
        cnt += ceil(1.0 * (v[i] - a * x) / b);
    }
    return cnt <= x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    ll l = 1, r = 500000;
    ll ans;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld", ans);
    return 0;
}