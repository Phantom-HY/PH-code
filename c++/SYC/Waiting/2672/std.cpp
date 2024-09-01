#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(int n, int m)
{
    ll cnt = 1;
    for (int i = n; i >= n - m + 1; i--)
        cnt *= i;
    for (int i = 2; i <= m; i++)
        cnt /= i;
    return cnt;
}
int n;
ll cnt = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    int m = n / 2;
    for (int i = 2; i <= m - 1; i++)
        cnt *= i;
    printf("%lld\n", C(n, m) * cnt * cnt / 2);
    return 0;
}