#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
struct node
{
    int fa = -1;
    vector<int> son;
} a[105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].son.push_back(y);
        a[y].fa = x;
    }
    int root, max_son = 0, id;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].fa == -1)
            root = i;
        if (max_son<a[i].son.size())
            max_son = a[i].son.size(),id=i;
    }
    printf("%d\n%d\n", root, id);
    sort(a[id].son.begin(),a[id].son.end());
    for (int i = 0; i < a[id].son.size(); i++)
        printf("%d ", a[id].son[i]);
    return 0;
}