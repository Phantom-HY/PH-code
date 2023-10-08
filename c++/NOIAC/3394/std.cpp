#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    ll a, b, c, d;
    a = b = c = d = n / 4;
    a += n % 4 >= 1;
    b += n % 4 >= 2;
    c += n % 4 >= 3;
    if (a != 0)
        a = (a * 4 - 2) / 2 * a;
    if (b != 0)
        b = b * 2 * b;
    if (c != 0)
        c = (c * 4 + 2) / 2 * c;
    if (d != 0)
        d = (d * 4 + 4) / 2 * d;
    printf("%lld %lld", a - c, b - d);
    return 0;
}