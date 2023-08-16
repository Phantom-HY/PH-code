#include <bits/stdc++.h>
using namespace std;
char str[1005];
int pos[1005];
long long solve(int l, int r)
{
    long long ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (!isalpha(str[i]))
            continue;
        long long num = 0;
        if (str[i] == 'f' && str[i + 1] == 'o') // 处理 for
        {
            sscanf(str + i + 4, "%lld", &num); // 获得循环次数
            int p1 = i;
            while (str[p1] != '|')
                p1++;
            ans += num * solve(p1 + 1, pos[i + 3] - 1); // 递归处理
            i = pos[i + 3];
        }
        else if (str[i] == 'f' || str[i] == 'b')
        {
            sscanf(str + i + 3, "%lld", &num); // 获取移动距离
            ans += (str[i] == 'f' ? 1 : -1) * num;
        }
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%s", str);
    int len = strlen(str);
    stack<int> s;
    for (int i = 0; i < len; i++)
        if (str[i] == '{')
            s.push(i);
        else if (str[i] == '}')
            pos[s.top()] = i, s.pop();
    printf("%lld", abs(solve(0, len - 1)));
    return 0;
}