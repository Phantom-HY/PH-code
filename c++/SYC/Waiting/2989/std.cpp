#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char m[15] = "12345678x";
char a[15];
struct node
{
    char str[15];
    int cnt;
    bool operator<(const node &a) const
    {
        return cnt > a.cnt;
    }
};
int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, cnt;

int countInversions(char a[])
{
    int count = 0;
    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (a[i] == 'x' || a[j] == 'x')
                continue;
            if (a[i] > a[j])
                count++;
        }
    }
    return count;
}
int h(char a[])
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        if (a[i] != 'x')
        {
            int j = a[i] - '0';
            sum += abs(i / 3 - j / 3) + abs(i % 3 - j % 3);
        }
    }
    return sum;
}
void bfs(char a[])
{
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%s", a);
    int sum = countInversions(a);
    if (sum % 2 != countInversions(m))
        printf("unsolvable"), exit(0);
    return 0;
}