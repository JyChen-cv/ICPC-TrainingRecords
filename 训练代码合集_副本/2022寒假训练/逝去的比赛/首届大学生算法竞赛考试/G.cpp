#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=100;
long long mapp[N+2][N+2],ji[N+2][N+2];
// long long po(long long x)
// {
//     if (x==0) return 1;
//     long long ls=po(x/2);
//     if (x%2==1) return ls*ls*2;
//     else return ls*ls;
// }

long long deal(long long x,long long y)
{
    long long ls=0;
    for (long long i=x;i<=y;i++) {
        ls*=10;
        ls+=mapp[i][i];
    }
    return ls;
}

long long main()
{
    long long num;
    std::cin>>num;
    std::vector<long long> l;
    while (num) {
        long long ls=num%10;
        l.push_back(ls);
        num/=10;
    }
    long long n=l.size();
    for (long long i=1;i<=n;i++) mapp[i][i]=l[l.size()-i];
    for (long long i=1;i<=n;i++) {
        for (long long j=i;j<=n;j++) {
            ji[i][j]=deal(i,j);
            // std::cout<<ji[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    for (long long len=2;len<=n;len++) {
        for (long long l=1;l+len-1<=n;l++) {
            long long r=l+len-1;
            for (long long k=l;k<r;k++) {
                mapp[l][r]+=ji[l][k]*((long long)1<<(r-k-1))+mapp[k+1][r];
            }
            mapp[l][r]+=ji[l][r];
            // std::cout<<l<<" "<<r<<" "<<mapp[l][r]<<std::endl;
        }
    }
    std::cout<<mapp[1][n]<<std::endl;
    return 0;
}