#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val, num;
    int fa;
    vector<int> child;
} v[100005];
int n, l;
void fun(int root)
{
    queue<int> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        auto k = q.front();
        q.pop();
        if (v[k].num == v[k].val)
            ans++;
        for (auto &&i : v[k].child)
        {
            v[i].num = max(v[i].num, v[k].num);
            q.push(i);
        }
    }
    printf("%d\n", ans);
    exit(0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i].val), v[i].num = v[i].val;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &l);
        while (l--)
        {
            int x;
            scanf("%d", &x);
            v[i].child.push_back(x);
            v[x].fa = i;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!v[i].fa)
            fun(i);
    return 0;
}