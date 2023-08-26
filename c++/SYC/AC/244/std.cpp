#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Tree
{
    int data;
    vector<int> child;
} tr[100005];
int n;
ll ans[100005];
int q, x;
ll fun(int x)
{
    if (tr[x].child.size() == 0)
        return ans[x] = tr[x].data;
    ll sum = tr[x].data;
    for (auto &&i : tr[x].child)
        sum += fun(i);
    return ans[x] = sum;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &tr[1].data);
    for (int i = 2; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        tr[x].child.push_back(i);
        tr[i].data = y;
    }
    fun(1);
    scanf("%d", &q);
    while (q--)
        scanf("%d", &x), printf("%lld\n", ans[x]);
    return 0;
}