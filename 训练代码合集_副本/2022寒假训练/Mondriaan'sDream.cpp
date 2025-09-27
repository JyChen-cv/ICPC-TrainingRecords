#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=11;
long long f[N+2][(1<<N)+2];
bool S[(1<<N)+2];
long long n,m,t[(1<<N)+2];

long long lowbit(long long x) 
{
    return x&(-x);
}
bool check(long long x)
{
    long long polong long=0;
    while (x) {
        long long l=t[lowbit(x)];
        if ((l-polong long)%2==1) return 0;
        else {
            x-=lowbit(x);
            polong long=l+1;
        }
    }
    if ((m-polong long)%2==1) return 0;
    return 1;
}

long long main()
{
    for (long long i=0;i<=N;i++) t[1<<i]=i;
    while (std::cin>>n>>m && n) {
        memset (S,0,sizeof(S));
        for (long long i=0;i<=(1<<N);i++) {
            if (check(i)) S[i]=1;
        }

        f[0][0]=1;
        for (long long i=1;i<=n;i++) {
            for (long long j=0;j<(1<<m);j++) {
                f[i][j]=0;
                for (long long k=0;k<(1<<m);k++) {
                    if ((j&k)==0 && S[j|k]) f[i][j]+=f[i-1][k];
                }
            }
        }
        std::cout<<f[n][0]<<std::endl;
    }

    return 0;
}