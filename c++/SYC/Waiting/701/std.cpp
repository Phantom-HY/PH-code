#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
char s[1005];
vector<int> a[305];
int idx[305];
int n;
int x[305], y[305];
int len;
int ans[10005];
void dfs(int x)
{
    for (int i = idx[x]; i < a[x].size(); i = idx[x])
    {
        idx[x] = i + 1;
        dfs(a[x][i]);
    }
    ans[++len] = x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", s);
            a[s[0]].push_back(s[strlen(s) - 1]);
            x[s[0]]++;
            y[s[strlen(s) - 1]]++;
        }
        int sum_1 = 0, sum_2 = 0;
        int st = 1;
        for (int i = 'a'; i <= 'z'; i++)
        {
            sum_1 += x[i] - y[i] == 1;
            if (x[i] - y[i] == 1)
                st = i;
            sum_2 += x[i] - y[i] == -1;
            if (abs(x[i] - y[i]) > 1)
                sum_1 = 4;
        }
        if (sum_1 > 1 || sum_2 > 1)
        {
            puts("The door cannot be opened.");
            continue;
        }
        memset(idx, 0, sizeof(idx));
        len = 0;
        dfs(st);
        for (int i = len; i >= 1; i--)
            printf("%c", ans[i]);
        if (len != n + 1)
            puts("The door cannot be opened.");
        else
            puts("Ordering is possible.");
    }
    return 0;
}