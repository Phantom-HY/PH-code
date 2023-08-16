#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int k;
int c[105];
int cnt[105];
ll sum = 1;
ll q(ll n, ll mod)
{
    ll sum = 1;
    // printf("C:%d\n",n);
    for (int i = 1; i <= n; i++)
        sum *= i, sum %= mod;
    return sum;
}
ll C(ll n, ll m, ll mod)
{
    if (m > n)
        return 1;
    ll s = q(n - m, mod);
    n = q(n, mod);
    m = q(m, mod);
    printf("%lld %lld %lld\n", n, m, s);
    return n / (s * m % mod) % mod;
}
int x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &k);
    if (k == 1 || k == 2)
        printf("1\n"), exit(0);
    for (int i = 1; i <= k; i++)
        scanf("%d", c + i), cnt[i] = c[i] - 1;
    sum = 1;
    x = 2;
    for (int i = 2; i <= k + 1; i++, x++)
    {
        printf("%d cnt[%d]:%d\n", x, i, cnt[i]);
        if (cnt[i - 1] == 0)
            continue;
        printf("%d %d\n", x, i);
        sum *= C(cnt[i - 1] + x - 1, x - 1, mod);
        printf("%lld\n", sum);
        sum %= mod;
        x += cnt[i - 1];
    }
    printf("%lld\n", sum);
    return 0;
}