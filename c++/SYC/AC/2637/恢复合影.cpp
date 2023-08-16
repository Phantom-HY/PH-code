#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, p[100005][6], n, a[100005];
bool cmp(int x,int y)
{
    int cnt=0;
    for (int i=1;i<=5;i++)
        cnt+=(p[x][i]<p[y][i]);
    return cnt>=3;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            p[x][i] = j;
        }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}