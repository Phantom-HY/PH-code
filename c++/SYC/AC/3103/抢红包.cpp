#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    if (n % m == 0)
    {
        for (int i = 1; i <= m; i++)
            printf("%d\n", n / m);
    }
    else if ((m - 1) % 10 != 0)
    {
        for (int i = 1; i < m; i++)
            printf("0.01\n");
        printf("%0.2lf", double(n * 1.0) - double(m * 1.0 - 1.0) * 0.01);
    }
    else
    {
        m -= 1;
        printf("0.02\n");
        for (int i = 1; i < m; i++)
            printf("0.01\n");
        m += 2;
        printf("%0.2lf", double(n * 1.0) - double(m * 1.0 - 1.0) * 0.01);
    }
    return 0;
}