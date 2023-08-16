#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans[10005];
void dfs(int x, int cnt, int len)
{
    if (cnt == 1)
    {
        if (len==1)return;
        printf("%d=", n);
        for (int i = 1; i <= len; i++)
            printf("%d%c", ans[i], "*\n"[i == len]);
        return;
    }
    for (int i = x; i <= cnt; i++)
    {
        if (cnt%i==0)
        {
            ans[len+1]=i;
            dfs(i,cnt/i,len+1);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    dfs(2,n,0);
    return 0;
}