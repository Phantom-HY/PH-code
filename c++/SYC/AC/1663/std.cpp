#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[600005], len;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int x = n;
    a[0] = -0x3f3f3f3f;
    for (int i = 1;i <= n;i++)
        if (a[i-1]<a[i]&&a[i+1]<a[i])
        {
            x = i;
            break;
        }
    while(m--)
    {
        int s;
        scanf("%d",&s);
        int *f = lower_bound(a+1,a+1+x,s);
        if (*f == s)
            printf("%d\n",f-a);
        else
        {
            f = lower_bound(a+1+x,a+n+1,s);
            if (*f == s)
                printf("%d\n",f-a);
            else
                printf("-1\n");
        }
    }
    return 0;
}