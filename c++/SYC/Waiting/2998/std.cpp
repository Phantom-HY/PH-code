#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int t, n;
int phi(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (__gcd(i, n) == 1)
            cnt++;
    return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll ans = 0;
        for (int i = 233; i <= n - 233; i++)
        {
            ans += phi(i) * int(n / i);
            ans %= mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}