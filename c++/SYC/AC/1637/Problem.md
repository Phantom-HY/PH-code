### 描述
给一个不包含`0`和`1`的**数字字符串**,每个数字代表一个字母,请返回其所有可能的字母组合

下图的手机按键图,就表示了每个数字可以代表的字母

<table><thead><tr><th style="text-align:center">1</th><th style="text-align:center">2<br>ABC</th><th style="text-align:center">3<br>DEF</th></tr></thead><tbody><tr><td style="text-align:center"><strong>4</strong><br><strong>GHI</strong></td><td style="text-align:center"><strong>5</strong><br><strong>JKL</strong></td><td style="text-align:center"><strong>6</strong><br><strong>MNO</strong></td></tr><tr><td style="text-align:center"><strong>7</strong><br><strong>PQRS</strong></td><td style="text-align:center"><strong>8</strong><br><strong>TUV</strong></td><td style="text-align:center"><strong>9</strong><br><strong>WXYZ</strong></td></tr></tbody></table>

### 输入格式
输入一行一个不包含`0`和`1`的数值字符串$s$,$0 \leq  \left|S \right| \leq 10$
### 输入样例 1
```
23
```
### 输出样例1
```
ad
ae
af
bd
be
bf
cd
ce
cf
```
### 样例解释
`2` 可以是 `a`, `b` 或 `c`
`3` 可以是 `d`, `e` 或 `f`