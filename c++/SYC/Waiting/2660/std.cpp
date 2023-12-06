#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int fa;
    int dep;
    int val;
    vector<int> ch;
} tree[100005];
bool vis[100005];
int t[100005];
void Get(int x, int fa = 0, int dep = 0)
{
    tree[x].fa = fa;
    tree[x].dep = dep;
    for (int i = 0; i < tree[x].ch.size(); i++)
    {
        if (vis[tree[x].ch[i]] == 0)
            vis[tree[x].ch[i]] = 1, Get(tree[x].ch[i], x, dep + 1);
    }
}
int fun(int x, int y)
{
    if (x == y)
        return tree[x].val;
    if (tree[x].dep > tree[y].dep)
        swap(x, y);
    memset(t, 0, sizeof(t));
    while (tree[x].dep != tree[y].dep)
    {
        t[tree[x].val]++;
        y = tree[y].fa;
    }
    while (x != y)
    {
        t[tree[x].val]++;
        x = tree[x].fa;
        t[tree[y].val]++;
        y = tree[y].fa;
    }
    t[tree[x].val]++;
    int ans = -1;
    for (int i = 0; i <= 100000; i++)
    {
        if (t[i] % 2 == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].ch.push_back(v);
        tree[v].ch.push_back(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &tree[i].val);
    Get(1);
    while (q--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 0)
            tree[x].val = y;
        else
            printf("%d\n", fun(x, y));
    }
    return 0;
}