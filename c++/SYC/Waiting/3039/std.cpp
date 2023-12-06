#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int p[1000005];
int st[1000005][25];
int mp[1000005];
int ans[1000005];
int s = 1;
void fun(int l, int r, int dep)
{
    // for (int i = 1; i <= dep; i++)
    //     printf("\t");
    // printf("%d %d\n", l, r);
    if (l == r)
    {
        if (ans[l] == 0)
            ans[l] = s++;
        return;
    }
    int l_x, r_x, l_y, r_y;
    l_x = l;
    r_x = l + (r - l) / 2;
    l_y = r_x + 1;
    r_y = r;
    int k_x, k_y;
    k_x = __lg(l_x - r_x + 1);
    k_y = __lg(l_y - r_y + 1);
    int sum_x, sum_y;
    sum_x = st[l_x][k_x];
    sum_y = st[l_y][k_y];
    if (sum_x == min(sum_x, sum_y))
    {
        fun(l_x, r_x, dep + 1);
        fun(l_y, r_y, dep + 1);
    }
    else
    {
        fun(l_y, r_y, dep + 1);
        fun(l_x, r_x, dep + 1);
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
        scanf("%d", &p[i]), mp[p[i]] = i;
    for (int i = 1; i <= n; i++)
        st[i][0] = p[i];
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
        {
            if (i + (1 << j) - 1 <= n)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    int k = __lg(n);
    int m = st[1][k], q = st[n - (1 << k) + 1][k];
    fun(1, n, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}