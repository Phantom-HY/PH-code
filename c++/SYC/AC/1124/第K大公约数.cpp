#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, a, b, k, s, f[2000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &a, &b, &k);
        s = 0;
        ll n = __gcd(a, b);
        for (ll i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                f[++s] = i;
                if (i * i != n)
                    f[++s] = n / i;
            }
        if (s < k)
            printf("-1\n");
        else
        {
            sort(f + 1, f + 1 + s);
            printf("%lld\n", f[s - k + 1]);
        }
    }
    return 0;
}