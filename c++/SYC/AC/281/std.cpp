#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105];
bool d[105];
bool vis[105];
bool fun(int x)
{
    if (x == 1)
        return d[1] = true;
    if (vis[x])
        return d[x];
    for (int i = x - 1; i >= 1; i--)
        if (a[i] + i >= x)
        {
            fun(i), vis[i] = 1;
            if (d[i])
                return d[x] = true;
        }
    return d[x] = false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    fun(n);
    puts(d[n] ? "Perfect" : "Oh, No");
    return 0;
}