#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node
{
    int node;
    int par = -1;
    int sib = -1;
    int deg;
    int dep;
    int hei;
    vector<int> child;
} a[35];
int idx, l, r;
int dfs(int x, int d)
{
    // printf("%d %d\n", x, d);
    a[x].dep = d;
    int cnt = d;
    for (int i = 0; i < a[x].child.size(); i++)
    {
        if (a[x].child[i] != -1)
            cnt = max(dfs(a[x].child[i], d + 1), cnt);
    }
    a[x].hei = cnt - d;
    return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &idx, &l, &r);
        a[idx].node = idx;
        a[idx].deg = (l != -1) + (r != -1);
        a[idx].child.push_back(l);
        a[idx].child.push_back(r);
        a[l].sib = r;
        a[r].sib = l;
        if (l != -1)
            a[l].par = idx;
        if (r != -1)
            a[r].par = idx;
    }
    for (int i = 0; i < n; i++)
        if (a[i].par == -1)
            dfs(i, 0);
    for (int i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", 
        a[i].node, a[i].par, a[i].sib, a[i].deg, a[i].dep, a[i].hei, 
        a[i].par == -1 ? "root" : a[i].deg == 0 ? "leaf": "internal node");
    }
    return 0;
}