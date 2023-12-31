### 问题描述
从一个大小为$n$的整数集中选取一些元素，使得它们的和等于给定的值$T$。
每个元素限选一次，不能一个都不选。

### 输入格式
第一行一个正整数$n$，表示整数集内元素的个数。
第二行$n$个整数，用空格隔开。
第三行一个整数$T$，表示要达到的和。
### 输出格式
输出有若干行，每行输出一组解，即所选取的数字，按照输入中的顺序排列。

若有多组解，优先输出不包含第$n$个整数的；

若都包含或都不包含，优先输出不包含第$n-1$个整数的，依次类推。

最后一行输出总方案数。

> 请使用二进制枚举实现

### 样例输入
```
5
-7 -3 -2 5 9
0
```
### 样例输出
```
-3 -2 5
-7 -2 9
2
```
### 数据规模和约定
对于全部数据$1 \leq n \leq 22，-2^{63} \leq T \lt 2^{63}$