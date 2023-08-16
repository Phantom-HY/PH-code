#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w, a[100005], tong[605];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        tong[a[i]]++;
        int num=max(1,(i*w/100)),cnt=0,ans;
        for (ans=600;i>=0&&cnt<num;ans--)
            cnt+=tong[ans];
        printf("%d ",ans+1);
    }
    return 0;
}