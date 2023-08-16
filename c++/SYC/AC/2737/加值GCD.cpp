#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005], b[200005], ans, cnt;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= m; i++)
        scanf("%lld", b + i);
    cnt = abs(a[2] - a[1]);
    for (int j = 3; j <= n; j++)
        cnt = __gcd(cnt, abs(a[j] - a[j - 1]));
    for (int i = 1; i <= m; i++)
    {
        printf("%lld\n", __gcd(cnt, a[n] + b[i]));
    }
    return 0;
}
/*
a1+b1 a2+b1 a3+b1
a3+b1 a2-a1 a3-a2
*/