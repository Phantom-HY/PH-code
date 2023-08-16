#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005], n, m;
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
        scanf("%c %d %d\n", &c, &x, &y);
        if (c == 'M')
            merge(x, y);
        else
            puts(find(x) == find(y) ? "Yes" : "No");
    }
    return 0;
}