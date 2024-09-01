#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f;
int k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &f, &k);
    if (f == 0)
    {
        int a = ceil(k * 1.0 / 750);
        printf("%.2lf",a*0.01);
    }
    else
    {
        int a = ceil(k * 1.0 / 500);
        printf("%.2lf",a*0.01);
    }
    return 0;
}