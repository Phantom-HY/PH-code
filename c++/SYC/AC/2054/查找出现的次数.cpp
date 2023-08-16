#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x;
unordered_map<int,int>c;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&x),c[x]++;
    while (m--)
    {
        scanf("%d",&x);
        printf("%d\n",c[x]);
    }
    return 0;
}