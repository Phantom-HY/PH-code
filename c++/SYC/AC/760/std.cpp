#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[1000005];
int q[1000005],h,e=-1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++)
        scanf("%d",a+i);
    for (int i = 1;i <= n;i++)
    {
        while(h <= e&&a[q[e]]>=a[i])e--;
        q[++e] = i;
        while(q[h] <= i - k)h++;
        if (i >= k)
            printf("%d ",a[q[h]]);
    }
    puts("");
    h = 0,e = -1;
    for (int i = 1;i <= n;i++)
    {
        while(h <= e&&a[q[e]]<=a[i])e--;
        q[++e] = i;
        while(q[h] <= i - k)h++;
        if (i >= k)
            printf("%d ",a[q[h]]);
    }
    return 0;
}