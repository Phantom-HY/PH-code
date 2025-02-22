#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node
{
    ll L;
    ll H;
} a[100005];
ll now;
ll tt, q[100005];
ll ans[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%d%d", &a[i].L, &a[i].H);
    a[0].H = 1e8;
    a[n + 1].H = 1e8;
    ll Minid = 0;
    for (ll i = 1; i <= n; i++)
        if (a[i].H <= a[Minid].H)
            Minid = i;
    q[++tt] = Minid;
    ll L, R;
    L = Minid - 1;
    R = Minid + 1;
    for (ll i = 1; i <= n; i++)
    {
        ll Len = 0;
        if (a[L].H < a[R].H)
        {
            while (tt && a[L].H > a[q[tt]].H)
            {
                a[q[tt]].L += Len;
                Len = a[q[tt]].L;
                ans[q[tt]] = now + a[q[tt]].L;
                now += a[q[tt]].L * (min(a[q[tt - 1]].H, a[L].H) - a[q[tt]].H);
                tt--;
            }
            a[L].L += Len;
            q[++tt] = L;
            L--;
        }
        else
        {
            while (tt && a[R].H > a[q[tt]].H)
            {
                a[q[tt]].L += Len;
                Len = a[q[tt]].L;
                ans[q[tt]] = now + a[q[tt]].L;
                now += a[q[tt]].L * (min(a[q[tt - 1]].H, a[R].H) - a[q[tt]].H);
                tt--;
            }
            a[R].L += Len;
            q[++tt] = R;
            R++;
        }
    }
    for (ll i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
    return 0;
}