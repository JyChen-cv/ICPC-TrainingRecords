#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

const long long N=10,M=100;
long long f[N+2][(1<<N)+2][M+2];
long long pot[(1<<N)+2],cnt[(1<<N)+2];
std::vector<long long> s;

inline long long lowbit(long long x) {return x&(-x);}

long long check(long long x)
{
    for (long long i=0;i<=N;i++) {
        if ((x>>i)&1 && (x>>(i+1))&1) return 0;
    }
    return 1;
}

inline long long count(long long x) 
{
    long long cnt=0;
    while (x) {
        cnt++;
        x-=lowbit(x);
    }
    return cnt;
}

long long main()
{
    for (long long i=0;i<=N;i++) pot[1<<i]=i;

    long long n,m;
    std::cin>>n>>m;// 最大大概到144，那么时间就是够的
    for (long long i=0;i<(1<<n);i++) {
        if (check(i)) {
            s.push_back(i);
            cnt[i]=count(i);
        }
    }

    f[0][0][0]=1;
    for (long long i=1;i<=n+1;i++) {
        for (long long k=0;k<=m;k++) { 
            for (long long j=0;j<(long long)s.size();j++) {
                if (k<cnt[s[j]]) continue;
                for (long long l=0;l<(long long)s.size();l++) {  // 上一层
                    // if (k<cnt[s[j]]+cnt[s[l]]) continue;
                    if (!(s[j]&s[l]) && check(s[j]|s[l]))  // 等效 if (!(s[j]&s[l]) && !(s[j]&(s[l]<<1)) && !(s[j]&(s[l]>>1)))
                        f[i][s[j]][k]+=f[i-1][s[l]][k-cnt[s[j]]];
                }
                // if (i==n && k==m) ans=std::max(ans,f[n][s[j]][m]);
            }
        }
    }
    std::cout<<f[n+1][0][m]<<std::endl; // 巧妙的省去累加答案状态的过程

    return 0;
}