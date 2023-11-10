#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool vis[1000005];
int ans[1000005];
int len;
int g(int x)
{
    int ans = 0;
    while (x)
    {
        ans++;
        x /= 2;
    }
    return ans;
}
int fan(int x, int len)
{
    int i = 0;
    int ans = 0;
    while (len--)
    {
        if (x % 2 == 0)
            ans += 1 << i;
        x /= 2;
        i++;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    len = g(n - 1);
    for (int i = 0; i < n; i++)
        ans[i] = i;
    for (int i = n - 1; i > 0; i--)
    {
        if ((ans[i] ^ i) == ans[i] + i)
            continue;
        for (int j = len; j >= 0; j--)
        {
            int y = fan(ans[i], j);
            if (y >= n)
                continue;
            if (vis[y] == 0)
            {
                vis[y] = vis[i] = 1;
                swap(ans[i], ans[y]);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}