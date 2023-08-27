#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll ans[25][25][25];
bool vis[25][25][25];
ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (ans[a][b][c] != 0)
        return ans[a][b][c];
    if (a < b && b < c)
        return ans[a][b][c] =
                   w(a, b, c - 1) +
                   w(a, b - 1, c - 1) -
                   w(a, b - 1, c);
    return ans[a][b][c] =
               w(a - 1, b, c) +
               w(a - 1, b - 1, c) +
               w(a - 1, b, c - 1) -
               w(a - 1, b - 1, c - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (scanf("%lld%lld%lld", &a, &b, &c), a != -1 || b != -1 || c != -1)
        printf("%lld\n", w(a, b, c));
    return 0;
}