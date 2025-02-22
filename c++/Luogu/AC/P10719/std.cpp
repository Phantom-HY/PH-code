#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
char s[1005][1005];
int cnt[1005][1005];
int ans = 1e9;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
        // for (int j = 1; j <= m; j++)
            scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (s[i][j] == '1');
    // for (int i = 1; i <= n; i++)
    //     for(int j = 1; j <= m; j++)
    //         printf("%d%c", cnt[i][j], " \n"[j == m]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int x = i; x <= n; x++)
                for (int y = j; y <= m; y++)
                    if (cnt[x][y] - cnt[i - 1][y] - cnt[x][j - 1] + cnt[i - 1][j - 1] >= k)
                        ans = min(ans, (x - i + 1) * (y - j + 1));
    printf("%d\n", ans != 1e9 ? ans : 0);
    return 0;
}