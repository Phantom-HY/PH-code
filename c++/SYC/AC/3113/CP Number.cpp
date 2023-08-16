#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
ll f(ll n)
{
    return (n + 1) / 2 + n / 4;
}
int main()
{
    scanf("%lld%lld", &l, &r);
    if (l > 0 && r > 0)
        printf("%lld", f(r) - f(l - 1));
    else if (l == 0 && r > 0)
        printf("%lld", f(r) + 1);
    else if (l < 0 && r > 0)
        printf("%lld", f(r) + f(abs(l)) + 1);
    else if (l < 0 && r == 0)
        printf("%lld", f(abs(l)) + 1);
    else if (l < 0 && r < 0)
        printf("%lld", f(abs(l)) - f(abs(r) - 1));
    return 0;
}