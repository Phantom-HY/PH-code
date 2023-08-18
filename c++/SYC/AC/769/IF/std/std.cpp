#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int s;
int t[5005], c[5005];
int ans = 1e9;
void dfs(int x, int sum, int T, int C)
{
    if (x == n + 1)
    {
        sum += T * C;
        ans = min(ans, sum);
        return;
    }
    dfs(x + 1, sum + T * C, T + s + t[x], c[x]);
    if (x != 1)
        dfs(x + 1, sum, T + t[x], C + c[x]);
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &s);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", t + i, c + i);
    dfs(1, 0, 0, 0);
    printf("%d\n", ans);
    return 0;
}