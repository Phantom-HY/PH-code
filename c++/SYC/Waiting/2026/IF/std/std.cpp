#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105];
int ans;
void dfs(int x, int y, int i)
{
    if (i == n + 1)
    {
        if (x == y)
            ans = max(ans, x);
        return;
    }
    dfs(x + a[i], y, i + 1);
    dfs(x, y + a[i], i + 1);
    dfs(x, y, i + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    dfs(0,0,1);
    if (ans==0)
        printf("Impossible");
    else
        printf("%d\n",ans);
    return 0;
}