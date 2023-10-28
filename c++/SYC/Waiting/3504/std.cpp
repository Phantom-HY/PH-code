#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[35];
map<pair<int, int>, bool> vis;
struct fun
{
    int x, y;
    int f;
};
void bfs(int x, int y)
{
    queue<fun> q;
    q.push(fun{x, y, 0});
    for (int i = 1; i <= n; i++)
    {
        int len = q.size();
        while (len--)
        {
            auto w = q.front();
            q.pop();
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
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    bfs(0, 0);
    printf("%d\n", vis.size());
    return 0;
}