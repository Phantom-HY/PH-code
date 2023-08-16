#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int d, v;
    bool operator<(const node t) const
    {
        return v < t.v;
    }
} a[500005];
int n, k, p, ans, l;
priority_queue<node> q;
bool cmp(node a, node b)
{
    return a.d < b.d;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].d, &a[i].v);
    scanf("%d%d", &p, &l);
    for (int i = 1; i <= n; i++)
        a[i].d = p - a[i].d;
    sort(a + 1, a + 1 + n, cmp);
    q.push({0, l});
    int cnt = 0, pos = 1;
    while (cnt < p && q.size())
    {
        ans++;
        cnt += q.top().v;
        q.pop();
        while (pos <= n && a[pos].d <= cnt)
            q.push(a[pos++]);
    }
    if (cnt < p)
        printf("-1");
    else
        printf("%d", ans - 1);
    return 0;
}