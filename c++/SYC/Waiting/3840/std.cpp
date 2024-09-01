#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k;
long long fib_1[105] = {0, 1, 0}, fib_2[105] = {0, 0, 1};
void init()
{
    for (int i = 3; i <= 100; i++)
        fib_1[i] = fib_1[i - 1] + fib_1[i - 2], fib_2[i] = fib_2[i - 1] + fib_2[i - 2];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    init();
    while (t--)
    {
        scanf("%d%d", &n, &k);
        int cnt = 0;
        long long x = fib_1[k], y = fib_2[k];
        for (long long i = 0; i * y <= n; i++)
            if ((n - i * y) % x == 0 && i > (n - i * y) / x)
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}