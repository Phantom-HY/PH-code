#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a[13];
int E()
{
    return a[5] + a[4] * 2 + a[3] * a[3] * 4 + a[2] * 8;
}
long double T()
{
    return a[6] * (1.0 / 2.0) + a[7] * (1.0 / 4.0) + a[8] * (1.0 / 8.0) + a[9] * (1.0 / 16.0) + a[10] * (1.0 / 32.0) + a[11] * (1.0 / 64.0) + a[12] * (1.0 / 128.0);
}
void fun()
{
    int e = E();
    long double t = T();
    if (a[1] == 1)
        printf("-");
    if (e == 15 && t == 0)
    {
        printf("INF\n");
        return;
    }
    else if (e == 15 && t != 0)
    {
        printf("NaN\n");
        return;
    }
    else if (e == 0 && t == 0)
    {
        printf("0\n");
        return;
    }
    printf("%0.15lf\n", pow(2, e - 7) * double(1.0 + t));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        string r;
        cin >> r;
        for (int i = 1; i <= 12; i++)
            a[i] = r[i - 1] - '0';
        fun();
    }
    return 0;
}