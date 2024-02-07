#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    k++;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), a[i] += a[i - 1];
    ll ans = 0;
    for (int i = k; i <= n; i++)
        ans = max(ans, a[i] - a[i - k]);
    printf("%lld\n", ans);
    return 0;
}