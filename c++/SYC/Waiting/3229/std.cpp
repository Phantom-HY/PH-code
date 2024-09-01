#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, y;
ll a[1005], b[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * b[i];
    printf("%lld", ans);
    return 0;
}