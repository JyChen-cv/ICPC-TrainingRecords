#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=1000;
long long mapp[N+2],f[N+2][N+2],ans[N+2][N+2];

void dfs(long long x,long long y)
{
    // std::cout<<x<<" ??? "<<y<<std::endl;
    if (y-x==1) {
        std::cout<<x<<" "<<y<<" ";
        return ;
    }
    if (x>=y) {
        std::cout<<y<<" ";
        return ;
    }
    if (ans[x][y]!=y) std::cout<<ans[x][y]<<" ";

    dfs(x,ans[x][y]-1);
    dfs(ans[x][y]+1,y);
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    for (long long i=1;i<=n;i++) f[i][i]=mapp[i];
    for (long long i=1;i+1<=n;i++) f[i][i+1]=mapp[i]+mapp[i+1];
    for (long long i=2;i<=n+1;i++) f[i][i-1]=1;
    for (long long len=3;len<=n;len++) {
        for (long long l=1;l+len-1<=n;l++) {
            long long r=l+len-1;
            long long ls=0;
            for (long long k=l+1;k<=r;k++) {
                // f[l][r]=std::max(f[l][r],f[l][k-1]*f[k+1][r]+mapp[k]);
                if (f[l][r]<f[l][k-1]*f[k+1][r]+mapp[k]) {
                    f[l][r]=f[l][k-1]*f[k+1][r]+mapp[k];
                    ans[l][r]=k;
                }
            }
        }
    }

    std::cout<<f[1][n]<<std::endl;
    dfs(1,n);
    return 0;
}

// 感觉这道题目最难想的不是区间dp，而是怎么可以想到利用区间dp来解决问题，我觉得问题的核心在于
// 对中序遍历形成的序列的性质还是不太掌握，所以不能一下挖掘到枚举断点找根这个思路，其实有了区间dp
// 之后便很容易想到这些了，枚举断点，找到根，先序遍历相当于就是把根进行输出，模拟一下正向的过程即可
// 然后就是对于特殊情况的出现没有警觉性，比如这道题目特意描述了关于子树为空之类的情况时的处理办法，应该
// 引起注意，这样才能提高正确率