#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, a[1050005];
bool p[1050005];
int bdfs(int x)
{
    queue<pair<int, int>> q;
    q.push({x, 0});
    p[x] = 1;
    while (q.size())
    {
        auto f = q.front();
        q.pop();
        if (f.x >= n)
            return f.y;
        if (f.x + a[f.x] >= n)
            return f.y + 1;
        if (p[f.x + a[f.x]] == 0)
            q.push({f.x + a[f.x], f.y + 1}),p[f.x + a[f.x]] = 1;
        for (int i = 0; i < f.x; i++)
            if (p[i] == 0)
                q.push({i, f.y + 1}), p[i] = 1;
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d", bdfs(0));
    return 0;
}