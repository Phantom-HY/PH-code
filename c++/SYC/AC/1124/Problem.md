### 题目描述
给定两个正整数$A,B$,请你找出第$k$大的公约数

如当$k=1$时,需要找出$\text{gcd(A,B)}$

但不存在第$K$大公约数时,输出`-1`
### 输入格式
第一行输入一个正整数$T$,表示$T$组询问

接下来$T$行每行两个正整数$A,B,K$
### 输出格式
每组询问输出一行一个整数表示第$k$大的公约数
不存在第$K$大公约数时,输出`-1`
### 输入样例
```
3
2 3 1
2 3 2
8 16 3
```
### 输出样例
```
1
-1
2
```
### 数据规模
对于$10\%$的数据$1 \leq A,B,K \leq 100$
对于$30\%$的数据$1 \leq A,B,K \leq 100000$
对于$100\%$的数据$1 \leq A,B,K \leq 10^{10},1 \leq T \leq 100$,保证$A = B$的询问次数不超过$10$(数据较为随机