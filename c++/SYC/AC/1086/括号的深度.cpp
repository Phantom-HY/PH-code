#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];
int cnt,ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == '(')
            cnt++,ans=max(cnt,ans);
        else 
            cnt--;
    printf("%d",ans);
    return 0;
}