#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[805][805];
// bool check(int mid)
// {
//     int x=mid/n,y=mid%n;
//     if (y==0)
//         y=n;
//     else
//         x++;
//     ll cnt=1e18;

// }
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=n-k+1;j++)
        {
            for (int x=i;x<=i+k-1;x++)
                for (int y=j;y<=j+k-1;y++)
                    ;
        }
    return 0;
}