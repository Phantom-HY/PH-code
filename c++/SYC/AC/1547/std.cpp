#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int x, y;
bool mp[11][11];
int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int ans[11], cnt;
void fun()
{
    int sum = 0;
    for (int i = 2; i <= n; i++)
        sum += mp[min(a[i], a[i - 1])][max(a[i], a[i - 1])];
    if (sum > cnt)
    {
        cnt = sum;
        for (int i = 1; i <= n; i++)
            ans[i] = a[i];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &x, &y), mp[min(x, y)][max(x, y)] = 1;
    do{
        fun();
    }while(next_permutation(a + 1, a + n + 1));
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}