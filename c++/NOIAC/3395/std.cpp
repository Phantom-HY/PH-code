#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n;
int a[100005], b[100005];
ll ans = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] <= b[i])
        {
            ans *= (b[i] - i + 1);
            ans %= mod;
        }
        else
            printf("0"), exit(0);
    printf("%lld", ans);
    return 0;
}