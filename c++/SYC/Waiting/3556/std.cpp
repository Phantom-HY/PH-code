#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
int a[100005], b[100005];
int l, r, L, R;
bool bl_1;
int st_a[100005][25], st_b[100005][25];
ll c[1005][1005];
ll st_c[1005][1005][25];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), bl_1 |= (a[i] <= 0);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]), bl_1 |= (b[i] <= 0);
    if (!bl_1)
    {
        for (int j = 0; j <= 20; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                if (j == 0)
                    st_a[i][j] = a[i];
                else
                    st_a[i][j] = max(st_a[i][j - 1], st_a[i + (1 << (j - 1))][j - 1]);
        for (int j = 0; j <= 20; j++)
            for (int i = 1; i + (1 << j) - 1 <= m; i++)
                if (j == 0)
                    st_b[i][j] = a[i];
                else
                    st_b[i][j] = min(st_b[i][j - 1], st_b[i + (1 << (j - 1))][j - 1]);
    }
    else if (n > 200 && n <= 1000 & m > 200 && m <= 1000)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                c[i][j] = a[i] * b[j];
        for (int x = 1; x <= n; x++)
            for (int j = 0; j <= 20; j++)
                for (int y = 1; y <= m; y++)
                    if (j == 0)
                        st_c[x][y][j] = c[x][y];
                    else
                        st_c[x][y][j] = min(st_c[x][y][j - 1],
                                            st_c[x][y - (1 << (j - 1))][j - 1]);
    }
    while (q--)
    {
        scanf("%d%d%d%d", &l, &r, &L, &R);
        if (!bl_1)
        {
            int k = log2(r - l + 1);
            int ans = max(st_a[l][k], st_a[r - (1 << k) + 1][k]);
            k = log2(R - L + 1);
            ans *= min(st_b[L][k], st_b[R - (1 << k) + 1][k]);
            printf("%d\n", ans);
        }
        else if (l == r && L == R)
            printf("%lld\n", a[l] * b[L]);
        else if (n <= 200 && m <= 200)
        {
            ll ans = -1e18;
            for (int i = l; i <= r; i++)
            {
                ll sum = 1e18;
                for (int j = L; j <= R; j++)
                    sum = min(sum, ll(a[i] * b[j]));
                ans = max(ans, sum);
            }
            printf("%lld\n", ans);
        }
        else if (n <= 1000 && m <= 1000)
        {
            int k = log2(R - L + 1);
            ll ans = -1e18;
            for (int i = l; i <= r; i++)
            {
                ans = max(ans, max(st_c[i][R - (1 << k) + 1][k], st_c[i][L][k]));
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}