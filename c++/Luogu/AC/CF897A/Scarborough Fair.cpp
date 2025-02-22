#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,l,r;
char a[105],x,y;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%c",a+i);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %c %c",&l,&r,&x,&y);
        for (int j=l;j<=r;j++)
        {
            if (a[j]==x)
                a[j]=y;
        }
    }
    for (int i=1;i<=n;i++)
        printf("%c",a[i]);
    return 0;
}