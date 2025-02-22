#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        n*=2;
        bool flag=1;
        int x,y;
        for (int i=2;i*i<=n;i++)
        {
            if (n%i!=0)
                continue;
            x=(n/i-i+1)/2,y=x+i-1;
            if ((n/i-i+1)%2==0)
            {
                printf("%d = %d",n/2,x);
                for (int j=x+1;j<=y;j++)
                    printf(" + %d",j);
                puts("");
                flag=0;
                break;
            }
        }
        if (flag)
            puts("IMPOSSIBLE");
    }
    return 0;
}