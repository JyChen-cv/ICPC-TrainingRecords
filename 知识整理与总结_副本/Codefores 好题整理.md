# Codefores 好题整理

### [Number of k-good subarrays](https://codeforces.com/contest/1982/problem/E)

用分而治之的思想解决问题，而且很准确的抓住了问题的本质。

### [Inscryption](https://codeforces.com/gym/104128/problem/G) 

避免错误的贪心，和那种汽车存油买油问题作区分！！！这个不是多多益善的，所以不能简单考虑。

### [Stone](https://codeforces.com/problemset/gymProblem/103428/F)

很有趣的博弈论，解释了博弈论很重要的本质，就是先手必胜情况肯定是一步就将对方杀死（某种程度上也可以考虑为不是尽可能的扩大自己受益，而是尽可能的缩小对手收益），否则就对方先手了，这个收益是一步到位的，不是逐步累加的。其次很重要的就是对于状态的划分，有点类似于状态机dp的状态划分的感觉。要知道什么是必输态很重要。这题目考查难度很高。

### [[GDCPC2023] Trading](https://www.luogu.com.cn/problem/P9692)

很好的题目，和股票买卖模型可以对比来看，他没有要求不能反回上一家店铺，这道题与顺序无关！！！！

### [PolandBall and White-Red graph](https://www.luogu.com.cn/problem/CF755E)

有点没懂证明，但是绝世好题的构造题，非常非常巧妙。

### [Med-imize](https://codeforces.com/contest/1993/problem/D)

与中位数有关，用常规手法处理想到二分不难。非常好的思维训练题，先写出朴素的dp方程，然后发现大量状态都是空的，考虑到是否可以优化到线性，然后找到相应的dp方程。

```c++
// 朴素 dp[i][j]表示前i个留下j个所能达到的最大的sum(b)
dp[i][j]=dp[i-1][j-1]+b[i];
if (i>=k) dp[i][j]=std::max(dp[i][j],dp[i-k][j]);
```

### [Distance to Different](https://codeforces.com/contest/1989/problem/E)

容斥dp

### [Turning Permutation](https://codeforces.com/gym/104869/problem/B)

### [vjudge dp](https://vjudge.net.cn/contest/645213#google_vignette)

### [Eliminating Balls With Merging (Easy Version)](https://codeforces.com/contest/1998/problem/E1)

分治好题

[**Permute K times**](https://atcoder.jp/contests/abc367/tasks/abc367_e)

第一眼看过去想了一颗基环树森林，每次找到环，然后在环上%一下就好了。但是缺点是代码太复杂了。

看了题解后发现是倍增找父亲，顿时就好写很多很多了

[**Sakurako's Hobby**](https://codeforces.com/contest/2008/problem/D)

第一眼看过去又以为是一颗内向的基环树，不会码了。。。其实就是一个环。主要对比一下和上一道题目的差别。这题多了一个限制就是给出的是一个排列。我们知道排列的话一定不会出现两个相同的数字，也就是说每个节点的入度都是1，那么自然就是构成了一个环而不是内向基环树。dsu一下就解决了。

### [E. Tree Pruning](https://codeforces.com/contest/2019/problem/E)

很好的一道思考题，问问自己会不会预处理！



### [C. Squaring](https://codeforces.com/contest/1995/problem/C)

很有趣的小结论题



### [world is mine](https://codeforces.com/problemset/problem/1987/D)

推式子然后转移！！！

是一类型的题目，这类型的题目通常难在观察出结论，因为这个贪心结论不好用语言描述，不是一个整体的约束，而是对每一项都有的约束。

难点1在转化式子，难点2在有式子后去设计一个合理的dp状态，这题目评分才1800，只能说感觉这种类型的题目着实是弱点

官方题解就很好



### [The Omnipotent Monster Killer](https://codeforces.com/problemset/problem/1988/D)



// 和没有上司的舞会很像，相当于重复log次没有上司的舞会，三次删完全部元素是肯定错误的，log次删除完全部元素才正确
// 难点：容易想错结论，正确结论不好证明，但是想一想又觉得肯定对。。。



// 其实就是可以在没有上司的舞会的基础上的一个拓展
// 没有上司的舞会 dp[i][0/1] 表示不选/选第i个节点时，以i为根的子树所能产生的最大价值
// 换一个角度理解，dp[i][0/1] 表示第 0/1 次选第i个节点时，以i为根的子树所能产生的最大价值

// dp[i][j(0~19)] 表示第j次选第i个节点时，以i为根的子树所能产生的最大贡献，由于没有其他的限制，那么转移就很显然了
// 然后用了一些实现技巧把时间复杂度从 log^2 压缩到了 log



### [A Game On Tree](https://qoj.ac/contest/1817/problem/9530)

// 很巧妙的题目
// 首先根据期望的贡献公式把贡献分成两个部分（自己的贡献和两两相互的贡献）
// （平方的期望一般都这么处理，不然就只能按照定义枚举E(x^2)的x进行计算，这显然是无法做到的）
// 然后第一部分直接可以统计
// 第二部分其实是一个路径问题，而且是一个与树的结构无关的统计！
// 想到了什么！
// 显然可以转化成点分治的思考方式来解决。不过这里由于统计的性质比较简单，所以并不用真的去用点分治重新建树计算，直接简单的换根dp就可以了
// 由于这里是边的最近公共祖先，所以和点的讨论稍微有些区别
// 后续转移的过程中还用到了一些简单的线性代数知识作数学优化，不然最坏情况就会变成 O(n^2)
