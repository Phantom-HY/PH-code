#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        k = n / l;
        r = n / k;
        ans += (r - l + 1) * k;
    }
    printf("%lld", ans);
    return 0;
}