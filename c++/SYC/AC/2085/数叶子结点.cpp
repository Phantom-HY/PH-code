#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
struct node
{
    int fa = -1;
    vector<int> son;
} a[105];
int ans;
void bfs(int x)
{
    queue<int> s;
    s.push(x);
    while (s.size())
    {
        int len = s.size();
        int cnt = 0;
        // printf("%d\n",len);
        for (int i = 1; i <= len; i++)
        {
            int c = s.front();
            s.pop();
            if (a[c].son.empty())
                cnt++;
            else
                for (auto &&i : a[c].son)
                    s.push(i);
        }
        printf("%d ", cnt);
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
        int id, x, y;
        scanf("%d%d", &id, &x);
        for (int j = 1; j <= x; j++)
        {
            scanf("%d", &y);
            a[id].son.push_back(y);
            a[y].fa = id;
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i].fa == -1)
        {
            bfs(i);
            break;
        }
    return 0;
}