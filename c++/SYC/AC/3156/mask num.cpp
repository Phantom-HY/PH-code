#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[25];
ll n, len, cnt[65];
void f(ll x)
{
    int k = 0;
    while (x)
    {
        if (x % 2)
            a[++len] = k;
        x /= 2, k++;
    }
}
void bdfs(ll x, ll step)
{
    if (x == 0)
    {
        printf("%lld\n", step);
        return;
    }
    bdfs(x - 1, step);
    bdfs(x - 1, step + cnt[a[x]]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    f(n);
    for (ll i = 0, k = 1; i <= 62 && k <= 2e18; i++, k *= 2)
        cnt[i] = k;
    bdfs(len, 0);
    return 0;
}