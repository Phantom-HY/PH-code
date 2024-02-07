#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[100005];
int STMax[100005][25], STMin[100005][25];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 0; i <= 15; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            if (i == 0)
                STMax[j][i] = STMin[j][i] = a[j];
            else
                STMax[j][i] = max(STMax[j][i - 1], STMax[j + (1 << (i - 1))][i - 1]),
                STMin[j][i] = min(STMin[j][i - 1], STMin[j + (1 << (i - 1))][i - 1]);
    int l = log2(k);
    for (int i = 1; i + k - 1 <= n; i++)
        printf("%d %d\n",max(STMax[i][l], STMax[i + k - (1 << l)][l]),min(STMin[i][l], STMin[i + k - (1 << l)][l]));
    return 0;
}