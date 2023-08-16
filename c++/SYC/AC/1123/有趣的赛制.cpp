#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll a, t, b;
    bool operator<(const node i) const
    {
        return i.t * b > t * i.b;
    }
} s[500005];
int n, m, cnt;
ll ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &s[i].a, &s[i].b, &s[i].t);
    sort(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (cnt + s[i].t > m)
            break;
        cnt += s[i].t;
        ans += s[i].a - s[i].b * cnt;
    }
    printf("%lld", ans);
    return 0;
}