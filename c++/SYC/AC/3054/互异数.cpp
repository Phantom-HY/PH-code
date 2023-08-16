#include <bits/stdc++.h>
using namespace std;
long long k, fac[21], len = 16, cnt[21], b[21], T = 53319412081140;
bool vis[21];
char str[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
long long A(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n] / fac[n - m];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 21; i++)
        fac[i] = fac[i - 1] * i;
    scanf("%lld", &k);
    for (int i = 16; i; i--)
        cnt[i] = cnt[i + 1] + 15 * A(15, i - 1); // 求出各数位的互异数个数,求出前缀和
    k = T - k + 1;                               // 转成全局第 S 大
    while (k > cnt[len])                         // 确定位数
        len--;
    k -= cnt[len + 1];             // 转为长度为 len 的第 S 大
    for (int i = 1; i <= len; i++) // 逐数位考虑
        for (int j = 15; j >= (i == len ? 1 : 0); j--)
        {
            if (vis[j])
                continue;
            long long x = A(16 - i, len - i);
            if (k > x)
                k -= x;
            else
            {
                vis[j] = true, putchar(str[j]);
                break;
            }
        }
    return 0;
}