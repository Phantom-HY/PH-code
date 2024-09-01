#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, r;
int st[1000005], pos;
ll p[1000005];
int cnt[1000005];
int o[1000005];
void fun(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            p[++pos] = i;
        for (ll j = 1; j <= pos && i * p[j] <= n; j++)
        {
            st[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (~scanf("%d%d", &l, &r))
    {
        memset(st, 0, sizeof st);
        memset(o, 0, sizeof o);
        pos = 0;
        fun(sqrt(r));
        for (int i = 1; i <= pos; i++)
        {
            ll s = max(ll(2), ll(ceil(l / p[i]))) * p[i];
            while (s <= r)
            {
                if (s - l >= 0)
                    o[s - l] = 1;
                s += p[i];
            }
        }
        int x, y, minx, miny, maxx, maxy;
        x = y = 0;
        minx = 0;
        miny = 1e9;
        maxx = maxy = 0;
        if (l == 1)
            o[0] = 1;
        for (int i = 0; i <= r - l; i++)
            if (o[i] == 0)
            {
                x = y;
                y = i + l;
                if (x > 0 && y > 0)
                {
                    if (miny - minx > y - x)
                        miny = y, minx = x;
                    if (maxy - maxx < y - x)
                        maxy = y, maxx = x;
                }
            }
        if (miny == 1e9)
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", minx, miny, maxx, maxy);
    }
    return 0;
}