#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

const long long N=100;
char c[N+2];
long long n;

bool deal(long long x1,long long x2,long long len)
{
    for (long long i=1;i<=len;i++) {
        if (c[x1+i-1]!=c[x2+i-1]) return 0;
    }
    return 1;
}

bool check(long long x)
{
    for (long long i=1;i+x-1<=n;i++) {
        for (long long j=i+1;j+x-1<=n;j++) {
            if (deal(i,j,x)) return 0;
        }
    }
    return 1;
}

long long main() {
    scanf("%d",&n);
    for (long long i=0;i<=n;i++) {
        scanf("%c",&c[i]);  // scanf读入会读入换行！！！
    }

    long long l=0,r=100;
    while (l<r) {
        long long mid=(l+r)/2;  // 二分还是要注意这里到底是想要怎么取证
        if (check(mid)) {
            r=mid;
        }
        else l=mid+1;
    }
    std::cout<<r<<std::endl;
    
    return 0;
}