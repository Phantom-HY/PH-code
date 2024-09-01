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
    scanf("%lld%lld%lld", &n, &x, &y);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    for (int i = 1; i <= n; i++)
        printf("%lld ", x * a[i] + y * b[i]);
    return 0;
}