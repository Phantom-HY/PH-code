#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll  a[500005], sum[500005];
int q[500005], h, e;
int k[500005];
ll ans = -1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        while (h <= e && sum[q[e]] >= sum[i])
            e--;
        q[++e] = i;
        while (q[h] <= i - m)
            h++;
        k[i] = q[h];
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, sum[i] - sum[k[i - 1]]);
    printf("%lld", ans);
    return 0;
}