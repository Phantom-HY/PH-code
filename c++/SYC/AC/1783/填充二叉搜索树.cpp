#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    int data;
    int sum;
    int l, r;
    int cnt;
} x[105];
int a[105];
int number(int j)
{
    if (j == -1)
        return 0;
    return x[j].cnt = number(x[j].l) +
                    number(x[j].r) + 1;
}
void dfs(int id, int l, int r)
{
    if (id == -1)
        return;
    x[id].sum = a[r - x[x[id].r].cnt+1];
    dfs(x[id].l, l, r - x[x[id].r].cnt-1);
    dfs(x[id].r, r - x[x[id].r].cnt + 1, r);
}
void bfs(int root)
{
    queue<int>q;
    q.push(root);
    while (!q.empty())
    {
        int len=q.size();
        for (int i = 0; i < len; i++)
        {
            int id=q.front();
            q.pop();
            printf("%d ",x[id].sum);
            if (x[id].l != -1)
                q.push(x[id].l);
            if (x[id].r != -1)
                q.push(x[id].r);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int c, d;
        scanf("%d%d", &c, &d);
        x[i].l = c;
        x[i].r = d;
        x[i].data = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    number(0);
    dfs(0, 0, n-1);
    bfs(0);
    return 0;
}