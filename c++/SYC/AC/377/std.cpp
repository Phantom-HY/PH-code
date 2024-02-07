#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int a, b, c;
    bool operator<(const node &t) const
    {
        return c > t.c;
    }
} p[100005];
int f[100005], n, m;
void init()
{
    for (int i = 1; i <= 2 * n; i++)
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
    sort(p + 1, p + m + 1);
    init();
    for (int i = 1; i <= m; i++)
    {
        if (find(p[i].a) == find(p[i].b))
            printf("%d\n", p[i].c),exit(0);
        merge(p[i].a, p[i].b + n);
        merge(p[i].b, p[i].a + n);
    }
    printf("0");
    return 0;
}