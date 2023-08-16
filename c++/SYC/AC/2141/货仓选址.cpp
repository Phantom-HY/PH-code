#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n, a[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        ans += abs(a[i] - a[(n + 1) / 2]);
    printf("%lld", ans);
    return 0;
}