#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char l[3], r[3];
struct tree
{
    int fa = -1;
    int l, r;
} a[35];
int Get_dep(int x, int dep = 0)
{
    if (x == -1)
        return 0;
    return max(Get_dep(a[x].l, dep + 1),
               Get_dep(a[x].r, dep + 1)) +
           1;
}
void bfs(int x, int dep)
{
    queue<int> q;
    q.push(x);
    int cnt = 1, sum = 0;
    while (q.size())
    {
        int len = q.size();
        bool jh = 0;
        for (int i = 0; i < len; i++)
        {
            int j = q.front();
            q.pop();
            // if (cnt == dep - 1)
            // printf(":%d %d %d\n", jh, j, cnt);
            if (cnt == dep - 1)
            {
                if (jh == 1 && (a[j].l != -1 || a[j].r != -1))
                    printf("NO %d", x), exit(0);
                if (a[j].r == -1)
                    jh = 1;
                if (a[j].l == -1 && jh == 0)
                    printf("NO %d", x), exit(0);
            }
            else if (cnt != dep)
            {
                if (a[j].l == -1 || a[j].r == -1)
                    printf("NO %d", x), exit(0);
            }
            if (a[j].l != -1)
                q.push(a[j].l), sum = a[j].l;
            if (a[j].r != -1)
                q.push(a[j].r), sum = a[j].r;
        }
        cnt++;
    }
    printf("YES %d", sum);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s\n", l, r);
        int x, y;
        if (l[0] == '-')
            x = -1;
        else if (l[1] >= '0' && l[1] <= '9')
            x = l[1] - '0' + (l[0] - '0') * 10;
        else
            x = l[0] - '0';
        if (r[0] == '-')
            y = -1;
        else if (r[1] >= '0' && r[1] <= '9')
            y = r[1] - '0' + (r[0] - '0') * 10;
        else
            y = r[0] - '0';
        a[i].l = x;
        a[i].r = y;
        a[x].fa = i;
        a[y].fa = i;
    }
    for (int i = 0; i < n; i++)
        if (a[i].fa == -1)
        {
            int dep = Get_dep(i);
            bfs(i, dep);
            break;
        }
    return 0;
}