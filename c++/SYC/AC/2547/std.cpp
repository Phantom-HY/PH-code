#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll h[100005];
stack<ll> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
            scanf("%lld", h + i);
        ll ans = 0;
        h[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            int idx = i;
            while (q.size() && h[i] <= h[q.top()])
            {
                idx = q.top();
                ll a = h[idx];
                ans = max(ans, a * (i - idx));
                q.pop();
            }
            q.push(idx);
            h[idx] = h[i];
        }
        printf("%lld\n", ans);
        while (!q.empty())
            q.pop();
    }
    return 0;
}