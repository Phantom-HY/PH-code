#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[10000005];
ll sum[10000005];
int ans=1e9;
bool flag = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i],flag |= a[i]<0;
    if (!flag)
    {
        int l = 1, r = n;
        while(1)
        {
            if (sum[r]-sum[l]<k&&sum[r-1]-sum[l-1]<k)
                break;
            if (sum[r]-sum[l]>=k)
                l++;
            else
                r--;
        }
        printf("%d", r-l+1==0?-1:r-l+1);
        exit(0);
    }
    for (int l = 1;l<=n;l++)
        for (int r = l; r <= n; r++)
            if (sum[r] - sum[l - 1]>=k)
                ans=min(ans,r-l+1);
    printf("%d", ans==0?-1:ans);
    return 0;
}