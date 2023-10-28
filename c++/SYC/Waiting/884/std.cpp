#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005];
int sum[1000005];
int ans;
int v(int a, int b)
{
    if (a != b)
        return 1;
    if (a == 0)
        return 1;
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        sum[i + 1] = s[i] - '0';
    for (int i = 1; i <= n; i++)
    {
        int x = sum[i];
        ans += x;
        for (int j = i+1; j <= n; j++)
            x = v(x, sum[j]), ans += x;
    }
    printf("%d\n", ans);
    return 0;
}