#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int k;
int cnt_1 = 1, cnt_2 = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= k; i++, cnt_1++, cnt_2++)
    {
        cnt_1 %= m, cnt_2 %= n;
        if (cnt_1 == 0)
            cnt_1 = m;
        if (cnt_2 == 0)
            cnt_2 = n;
        printf("%d %d\n", cnt_1, cnt_2);
    }
    return 0;
}