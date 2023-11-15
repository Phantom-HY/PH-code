#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &a, &b, &n);
    int ans = 0;
    while (a <= n && b <= n)
    {
        if (a > b)
            b += a;
        else
            a += b;
        ans++;
    }
    printf("%d", ans);
    return 0;
}