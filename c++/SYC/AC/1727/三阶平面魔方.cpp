#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
string a, b, c, s;
unordered_map<string, bool> p;
int bdfs(string x)
{
    queue<pair<string, int>> q;
    q.push({x, 0});
    p[x]=1;
    while (q.size())
    {
        auto f = q.front();
        q.pop();
        // cout << f.x[0] << f.x[1] << f.x[2] << '\n';
        // cout << f.x[3] << f.x[4] << f.x[5] << '\n';
        // cout << f.x[6] << f.x[7] << f.x[8] << "\n\n";
        if (f.x == "123456789")
        {
            return f.y;
        }
        for (int i = 0; i < 3; i++) // 右移
        {
            swap(f.x[i * 3 + 1], f.x[i * 3 + 2]);
            swap(f.x[i * 3], f.x[i * 3 + 1]);
            if (!p[f.x])
                q.push({f.x, f.y + 1}), p[f.x] = 1;
            swap(f.x[i * 3], f.x[i * 3 + 1]);
            swap(f.x[i * 3 + 1], f.x[i * 3 + 2]);
        }
        for (int i = 0; i < 3; i++) // 左移
        {
            swap(f.x[i * 3], f.x[i * 3 + 1]);
            swap(f.x[i * 3 + 1], f.x[i * 3 + 2]);
            if (!p[f.x])
                q.push({f.x, f.y + 1}), p[f.x] = 1;
            swap(f.x[i * 3 + 1], f.x[i * 3 + 2]);
            swap(f.x[i * 3], f.x[i * 3 + 1]);
        }
        for (int i = 0; i < 3; i++) // 上移
        {
            swap(f.x[i], f.x[3 + i]);
            swap(f.x[3 + i], f.x[6 + i]);
            if (!p[f.x])
                q.push({f.x, f.y + 1}), p[f.x] = 1;
            swap(f.x[3 + i], f.x[6 + i]);
            swap(f.x[i], f.x[3 + i]);
        }
        for (int i = 0; i < 3; i++) // 下移
        {
            swap(f.x[3 + i], f.x[6 + i]);
            swap(f.x[i], f.x[3 + i]);
            if (!p[f.x])
                q.push({f.x, f.y + 1}), p[f.x] = 1;
            swap(f.x[i], f.x[3 + i]);
            swap(f.x[3 + i], f.x[6 + i]);
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    s = a + b + c;
    cout << bdfs(s);
    return 0;
}