#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005], n, m;
int cnt[100005];
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i, cnt[i] = 1;
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
        f[fx] = fy, cnt[fy] += cnt[fx];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d\n", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        char c;
        scanf("%c %d ", &c, &x);
        if (c == 'M')
            scanf("%d\n", &y), merge(x, y);
        else if (c == 'Q')
            scanf("%d\n", &y), puts(find(x) == find(y) ? "Yes" : "No");
        else
            printf("%d\n", cnt[find(x)]);
    }
    return 0;
}