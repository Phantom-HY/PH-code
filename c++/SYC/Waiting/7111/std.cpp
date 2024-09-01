#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll l, r;
bitset<1000000005> mp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &l, &r);
        if (l == 1)
            printf("%lld\n", r);
        else
        {
            mp = 0;
            ll ans = 0;
            for (ll i = l; i < r; i++)
                for (ll j = l + 1; j <= r; j++)
                {
                    ll x = __gcd(i, j);
                    if (mp[x] == 0)
                        mp[x] = 1, ans++;
                }
            printf("%lld", ans);
        }
    }
    return 0;
}