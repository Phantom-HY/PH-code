#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],m,k[105];
vector<int>f[105];
int main(){
// #ifndef ONLINE_JUDGE
//     freopen("data.in", "r", stdin);
//     freopen("data.out", "w", stdout);
// #endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&k[i]);
        f[i].push_back(i);
        for (int j=1,x;j<=k[i];j++)
            scanf("%d",&x),f[i].push_back(x);
    }
    do
    {
        
    } while (next_permutation(f+1,f+1+n));
    
    return 0;
}