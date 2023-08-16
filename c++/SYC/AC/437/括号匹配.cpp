#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];
stack<int> s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == '(')
            s.push(i);
        else if (s.size()!=0)
            printf("%d %d\n", s.top(), i), s.pop();
    return 0;
}