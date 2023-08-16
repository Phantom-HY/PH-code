#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int w, v;
int W[100005], V[100005], pos;
int dp[100005];
int mp[15][15];
void fun(int w, int v, int s)
{
    for (int i = 1; s >= i; s -= i, i <<= 1)
        V[++pos] = i * v, W[pos] = i * w;
    if (s)
        V[++pos] = s * v, W[pos] = s * w;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w, &v), mp[w][v]++;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (mp[i][j])
                fun(i, j, mp[i][j]);
    for (int i = 1; i <= pos; i++)
        for (int j = m; j >= W[i]; j--)
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
    printf("%d\n", dp[m]);
    return 0;
}