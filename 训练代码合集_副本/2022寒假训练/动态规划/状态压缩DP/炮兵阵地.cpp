#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const long long N=100,M=10;
long long f[N+2][(1<<M)+2][(1<<M)+2];
long long mapp[N+2],pot[(1<<M)+2];
std::vector<long long> s;

long long lowbit(long long x) 
{
    return x&(-x);
}

long long count(long long x)
{
    long long cnt=0;
    while (x) {
        cnt++;
        x-=lowbit(x);
    }
    return cnt;
}

bool valid(long long x,long long y)  // y必须属于s
{
    if ((y|mapp[x])>mapp[x]) return 0;
    return 1;
}

bool check(long long x)
{
    long long ls=-3;
    while (x) {
        if (pot[lowbit(x)]-ls<3) return 0; 
        ls=pot[lowbit(x)];
        x-=lowbit(x);
    }
    return 1;
}

long long main()
{
    // freopen("data.in","r",stdin);
    for (long long i=0;i<=M;i++) pot[1<<i]=i;

    long long n,m;
    std::cin>>n>>m;
    for (long long i=0;i<(1<<m);i++) if (check(i)) s.push_back(i);

    for (long long i=1;i<=n;i++) {
        std::string c;
        std::cin>>c;
        for (long long j=0;j<(long long)c.size();j++) {   // mapp从0开始
            if (c[j]=='P') {
                mapp[i]<<=1;
                mapp[i]+=1;
            }
            else mapp[i]<<=1;
        }
    }
// 利用预处理+离散化优化
// 判断条件每层扔一个，更快
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        for (long long j=0;j<(long long)s.size();j++) { if (valid(i,s[j]))
            for (long long k=0;k<(long long)s.size();k++) { if (valid(i-1,s[k]) && (s[j]&s[k])==0)
                for (long long l=0;l<(long long)s.size();l++) {
                    if ((s[j]&s[l])==0) f[i][s[j]][s[k]]=std::max(f[i][s[j]][s[k]],f[i-1][s[k]][s[l]]+count(s[j]));  // & 的运算级低于 == !!!!!!
                }
                if (i==n) ans=std::max(ans,f[i][s[j]][s[k]]);
            }
        }
    }
    std::cout<<ans<<std::endl;
// 滚动数组优化

    return 0;
}