#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[10][138];
map<int,int>x;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=1<<n;i++)
        scanf("%d",&a[0][i]),x[a[0][i]]=i;
    for(int i=0;i<n-1;i++)
    {
        for (int j=1;j<=1<<(n-i);j+=2)
            a[i+1][(j+1)/2]=max(a[i][j],a[i][j+1]);
    }
    printf("%d",x[min(a[n-1][1],a[n-1][2])]);
    return 0;
}