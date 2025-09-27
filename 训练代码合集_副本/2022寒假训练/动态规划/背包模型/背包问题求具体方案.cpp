#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=1000;
const long long mod=1e9+7;
struct group {
    long long v;
    long long w;
} mapp[N+2];
long long n,m,f[N+2],rem[N+2][N+2],ans[N+2];

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i].v>>mapp[i].w;
    
    for (long long i=n;i>=1;i--) {
        for (long long j=m;j>=1;j--) {
            if (f[j]<=f[j-mapp[i].v]+mapp[i].w && j>=mapp[i].v) {
                f[j]=f[j-mapp[i].v]+mapp[i].w;
                rem[i][j]=j-mapp[i].v;
            }
            else rem[i][j]=j;
            // std::cout<<rem[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    long long tal=0,val=m;
    for (long long i=1;i<=n;i++) {
        if (val!=rem[i][val] && val!=0) {
            tal++;
            ans[tal]=i;
        }
        val=rem[i][val];
    }
    for (long long i=1;i<=tal;i++) {     //本来就是逆序的，所以倒是省去了反转，甚至可以省略ans数组，遍求遍输出
        std::cout<<ans[i]<<" ";
    }
    return 0;
}


//花了2h改完了这道题目，深有感触，首先要明白，出题人说按照字典顺序输出，大概率是为了不写spj，
//而不是为了增加难度，所以我门面对这种条件的时候，要把换算法，甚至增加一些专门的优化这类复杂思想往后放放
//往往只是改变一些循环的顺序，便能解决这样的问题，例如这道题目，便是在原有的题目基础上进行了倒序处理，
//这道题目浪费时间主要原因是因为倒序处理的时候很多地方都要翻过来，但是一开始总是意识不到，一直出错
//但是这也提醒我们，不要放弃，一点点地想清楚这个过程，面对手算不了的样例要用排除法尽量缩小手算的范围，或者说避免手算
//当思路不正确时，不要一昧地想着如何贴近答案，或者担心自己的语法错误，甚至怀疑计算机，
//反而要把计算机的结果作为已知条件代入自己的代码中，来找寻错误
//不要怕麻烦，积极地输出调试