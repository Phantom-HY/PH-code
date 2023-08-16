#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int u, v;
struct node
{
    int fa = -1;
    vector<int> ch;
} a[10005];
int cnt[10005];
bool s[10005];
void dfs(int x, int dep)
{
    // for (int i = 1; i <= dep; i++)
    //     printf("%d:", cnt[i]);
    // puts("");

    if (a[x].ch.empty())
    {
        printf("%d\n", x);
        s[x] = 1;
        for (int i = dep - 1; i >= 1; i--)
            if (s[cnt[i]])
                break;
            else
                printf("%d\n", cnt[i]), s[cnt[i]] = 1;
        return;
    }
    if (a[x].ch.size() == 2)
    {
        if (a[x].ch[0] > a[x].ch[1])
            swap(a[x].ch[0], a[x].ch[1]);
    }
    cnt[dep] = x;
    for (auto &&i : a[x].ch)
    {
        dfs(i, dep + 1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        a[v].fa = u;
        a[u].ch.push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (a[i].fa = -1)
        {
            dfs(i, 1);
            break;
        }
    return 0;
}