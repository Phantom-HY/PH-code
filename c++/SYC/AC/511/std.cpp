#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &a, &b);
    while (__gcd(a, b) != 1)
        b /= __gcd(a, b);
    if (b == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}