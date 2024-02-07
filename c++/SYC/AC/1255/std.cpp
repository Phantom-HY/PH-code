#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[150005], n, m;
void init()
{
    for (int i = 1; i <= 3 * n; i++)
        f[i] = i;
}
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    init();
    while (m--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (op == 1)
        {
            if (find(x) == find(y + n) ||
                find(x + n) == find(y))
                ans++;
            else
            {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + n + n, y + n + n);
            }
        }
        else
        {
            if (find(x) == find(y) ||
                find(x) == find(y + n))
                ans++;
            else
            {
                merge(x + n, y);
                merge(x, y + n + n);
                merge(x + n + n, y + n);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}