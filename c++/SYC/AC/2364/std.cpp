#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
unordered_map<int, int> mp;
int f[2000005], n, m;
void init()
{
    for (int i = 1; i <= n; i++)
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
int pos, p[2000005][3];
int cnt;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &m);
        n = 2000000;
        init();
        pos = 0;
        cnt = 0;
        mp.clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, op;
            scanf("%d%d%d", &x, &y, &op);
            if (mp[x] == 0)
                mp[x] = ++cnt;
            if (mp[y] == 0)
                mp[y] = ++cnt;
            x = mp[x];
            y = mp[y];
            if (op == 1)
                merge(x, y);
            else
                p[++pos][0] = x, p[pos][1] = y;
        }
        bool flag = 0;
        for (int i = 1; i <= pos; i++)
        {
            int x = p[i][0], y = p[i][1];
            if (find(x) == find(y))
            {
                flag = 1;
                break;
            }
        }
        printf("%s\n", flag ? "NO" : "YES");
    }
    return 0;
}