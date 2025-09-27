#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

const long long N=12,Mod=1e8;
long long mapp[N+2],n,m;
long long f[N+2][(1<<N)+2];
std::vector<long long> s;

bool valid(long long x,long long y)
{
    if ((mapp[x]|y)>mapp[x]) return 0;
    else return 1;
}

bool check(long long x)
{
    for (long long i=0;i<m;i++) {
        if ((x>>i)&1 && (x>>(i+1))&1) return 0;
    }
    return 1;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            long long c;
            std::cin>>c;
            mapp[i]<<=1;
            mapp[i]+=c;
        }
    }
    for (long long i=0;i<(1<<m);i++) if (check(i)) s.push_back(i);

    f[0][0]=1;
    for (long long i=1;i<=n+1;i++) {
        for (long long j=0;j<(long long)s.size();j++) { if (valid(i,s[j]))
            for (long long l=0;l<(long long)s.size();l++) { if (valid(i-1,s[l]))
                if (!(s[j]&s[l])) {
                    f[i][s[j]]+=f[i-1][s[l]];
                    f[i][s[j]]%=Mod;
                }
            }
        }
    }
    std::cout<<f[n+1][0]<<std::endl;

    return 0;
}