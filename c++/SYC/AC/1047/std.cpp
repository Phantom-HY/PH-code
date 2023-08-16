#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll d[4][1000005];
int t;
int x, y;
ll cnt = 1, cntx = 1, cnty = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    d[1][0] = d[2][0] = d[3][0] = 1;
    scanf("%d", &t);
    for (int i = 1; i <= 1e6; i++)
    {
        d[1][i] = cnt, d[1][i] %= mod;
        cnt += d[1][i], cnt %= mod;
    }
    for (int i = 2; i <= 1e6; i += 2)
    {
        d[2][i] = cntx, d[2][i] %= mod;
        cntx += d[2][i], cntx %= mod;
    }
    cntx = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        if (i % 2 == 0)
        {
            d[3][i] += cntx, d[3][i] %= mod;
            cnty += d[3][i], cnty %= mod;
        }
        else
        {
            d[3][i] += cnty, d[3][i] %= mod;
            cntx += d[3][i], cntx %= mod;
        }
    }
    while (t--)
    {
        scanf("%d%d", &x, &y);
        printf("%lld\n", d[x][y]);
    }
    return 0;
}