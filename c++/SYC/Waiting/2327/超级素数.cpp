//90分 SF一个点
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int o[5] = {0, 2, 3, 5, 7};
int n;
vector<int> ans;
bool check(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void bfs(int x)
{
    queue<int> q;
    for (int i = 1; i <= 4; i++)
        q.push(o[i]),ans.push_back(o[i]);
    while (1)
    {
        auto f = q.front();
        q.pop();
        for (int i = 1; i <= 9; i++)
        {
            if (check(f) && check(f * 10 + i))
            {
                q.push(f * 10 + i);
                if(f * 10 + i>n)return;
                else ans.push_back(f * 10 + i);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    bfs(n);
    printf("%d\n", ans.size());
    for (auto &&i : ans)
    {
        printf("%d\n", i);
    }
    return 0;
}