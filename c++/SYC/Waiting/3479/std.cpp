#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define d2 "%lld%lld"
ll t;
ll k;
ll p[505], C[505];
ll ans;
void dfs(ll x, ll y, ll a, ll b, ll c)
{
    // printf("x: %lld y: %lld a: %lld b: %lld c: %lld\n", x, y, a, b, c);
    if (x == k + 1)
    {
        ans = min(ans, 2 * a * b + 2 * a * c + 2 * b * c);
        return;
    }
    if (y == 0)
        return dfs(x + 1, C[x + 1], a, b, c);
    dfs(x, y - 1, a * p[x], b, c);
    dfs(x, y - 1, a, b * p[x], c);
    dfs(x, y - 1, a, b, c * p[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &k);
        for (ll i = 1; i <= k; i++)
            scanf(d2, &p[i], &C[i]);
        ans = 0x3f3f3f3f;
        dfs(1, C[1], 1, 1, 1);
        printf("%lld\n", ans);
    }
    return 0;
}