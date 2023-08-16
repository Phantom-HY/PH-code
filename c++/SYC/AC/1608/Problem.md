###问题描述
当你新建一个$word$文档时,会得到一个名为`新建 Microsoft Word 文档.doc`的文件
再新建一个则名为`新建 Microsoft Word 文档(2).doc`
再新建便是`新建 Microsoft Word 文档(3).doc`

不断新建,编号不断递增

倘若你现在新建了三个文档,然后删除了`新建 Microsoft Word 文档(2).doc`,再新建就又会得到一个`新建 Microsoft Word 文档(2).doc`

严格说,$Windows$在每次新建文档时,都会选取一个与已有文件编号不重复的最小正整数作为新文档的编号

请编程模拟以上过程,支持以下两种操作:

+ $\text{New}$：新建一个$word$文档,反馈新建的文档的编号

+ $\text{Delete id}$：删除一个编号为$id$的$word$文档,反馈删除是否成功

初始时一个文件都没有,`新建 Microsoft Word 文档.doc`的编号算作$1$
###输入格式
第一行一个正整数$n$表示操作次数,接下来$n$行,每行表示一个操作

若该行为$\text{New}$,则表示新建
若为$\text{Delete id}$则表示要删除编号为$id$的文档,其中$id$为一个正整数

操作按输入顺序依次进行
###输出格式
对于输入的每一行,输出其反馈结果

对于新建操作,输出新建的文档的编号

对于删除操作,反馈删除是否成功：
如果删除的文件存在,则删除成功,输出`Successful`
否则输出`Failed`
###样例输入
```
12
New
New
New
Delete 2
New
Delete 4
Delete 3
Delete 1
New
New
New
Delete 4
```
###样例输出
```
1
2
3
Successful
2
Failed
Successful
Successful
1
3
4
Successful
```
###数据规模和约定
对于$50\%$的数据,操作数$ \leq 1000$,最大$id \leq 1000$

对于$100\%$的数据,操作数$ \leq 100000$,最大$id \leq 100000$