#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int p, q;
struct node
{
    int pre, net;
} a[200005];
void link(int x, int y)
{
    a[x].net = y;
    a[y].pre = x;
}
void del(int x)
{
    link(a[x].pre, a[x].net);
}
void insert(int x, int y)
{
    link(y, a[x].net);
    link(x, y);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n + 1; i++)
        link(i - 1, i);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d", &p);
            if (p == a[0].net)
                continue;
            del(p), insert(0, p);
        }
        else if (x == 2)
        {
            scanf("%d", &p);
            if (p == a[n + 1].pre)
                continue;
            del(p), insert(a[n + 1].pre, p);
        }
        else
        {
            scanf("%d%d", &p, &q);
            if (p == q)
                continue;
            del(p), insert(q, p);
        }
    }
    for (int i = a[0].net; i != n + 1; i = a[i].net)
        printf("%d ", i);
    return 0;
}