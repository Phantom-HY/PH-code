#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll yh[1005][1005];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    for (int i = 0; i <= 1000; i++)
        yh[i][0] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i; j++)
            yh[i][j] = yh[i - 1][j] ^ yh[i - 1][j - 1];
    // for (int i = 0; i <= 20; i++)
    //     for (int j = 0; j <= i; j++)
    //         printf("%lld%c", yh[i][j], " \n"[j == i]);
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += (yh[n][i] == 0);
    if (ans%2 == 0)
        puts("even");
    else
        puts("odd");
    printf("%d",ans);
    return 0;
}