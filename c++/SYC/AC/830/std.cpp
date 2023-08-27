#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int cnt[100005][25];
struct Tree
{
    int data;
    vector<int> node;
} a[100005];
void merge(int a[], int b[], int s[])
{
    int len_a = 1, len_b = 1;
    int c[25];
    for (int i = 1; i <= 20; i++)
        if (a[len_a] > b[len_b])
            c[i] = a[len_a++];
        else
            c[i] = b[len_b++];
    for (int i = 1; i <= 20; i++)
        s[i] = c[i];
}
bool vis[100005];
void fun(int x)
{
    vis[x] = 1;
    cnt[x][1] = a[x].data;
    if (a[x].node.size() == 0)
        return;
    for (auto &&i : a[x].node)
        if (!vis[i])
        {
            vis[i] = 1;
            fun(i);
            merge(cnt[x], cnt[i], cnt[x]);
        }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    memset(cnt, -1, sizeof(cnt));
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].data);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].node.push_back(y);
        a[y].node.push_back(x);
    }
    fun(1);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", cnt[x][y]);
    }
    return 0;
}