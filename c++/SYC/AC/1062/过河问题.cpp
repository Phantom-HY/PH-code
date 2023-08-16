#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005],n,t;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int ans=0;
        while (n)
        {
            if (n==1)
            {
                ans+=a[0];
                break;
            }
            else if (n==2)
            {
                ans+=a[1];
                break;
            } 
            else if (n==3)
            {
                ans+=a[0]+a[1]+a[2];
                break;
            }
            else
            {
                int i=a[n-1]+a[n-2]+2*a[0],j=2*a[1]+a[n-1]+a[0];
                ans+=min(i,j);
                n-=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}