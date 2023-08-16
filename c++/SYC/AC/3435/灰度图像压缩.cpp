#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct T
{
    int x;   // 数值
    int cnt; // 数量
} e[305];
int x[256];
bool ch(T a, T b)
{
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.x<b.x;
}
int ct(char i, char j)
{
    if (i >= '0' && i <= '9')
        i -= '0';
    else
        i -= 'A' - 10;
    if (j >= '0' && j <= '9')
        j -= '0';
    else
        j -= 'A' - 10;
    return i * 16 + j;
}
void nct(int a)
{
    int i, j;
    i = a % 16;
    a /= 16;
    j = a % 16;
    if (i >= 0 && i <= 9)
        i += '0';
    else
        i += 'A' - 10;
    if (j >= 0 && j <= 9)
        j += '0';
    else
        j += 'A' - 10;
    printf("%c%c", j, i);
}
char str[125];
int jy[25][35], len;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i <= 256; i++)
        e[i].x = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        len = strlen(str);
        for (int j = 0; j < len; j += 2)
        {
            int x = ct(str[j], str[j + 1]);
            jy[i][j / 2 + 1] = x;
            e[x].cnt++;
        }
    }
    sort(e, e + 266, ch);
    for (int i = 0; i < 16; i++)
        nct(e[i].x);
    puts("");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= len/2; j++)
        {
            int bh = 0;
            for (int y = 1; y < 16; y++)
                if (abs(e[bh].x - jy[i][j]) > abs(e[y].x - jy[i][j]))
                    bh = y;
            printf("%c",bh>9?bh-10+'A':bh+'0');
        }
        puts("");
    }
    return 0;
}