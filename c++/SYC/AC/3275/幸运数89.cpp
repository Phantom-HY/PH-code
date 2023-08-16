#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int ans[10000005];
int len;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    do
    {
        if (n % 2 == 0)
            ans[++len] = 9, n = (n - 2) / 2;
        else
            ans[++len] = 8, n = (n - 1) / 2;
    } while (n >= 1);
    while (len)
    {
        printf("%d", ans[len--]);
    }
    return 0;
}