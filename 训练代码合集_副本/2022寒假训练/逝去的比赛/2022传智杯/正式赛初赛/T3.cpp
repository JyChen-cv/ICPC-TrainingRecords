#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>

const long long N=200000;
char mapp[N+4];

long long dea(long long x)
{
    long long re=0;
    while (x) {
        long long ls=x%10;
        x-=ls;
        x/=10;
        re++;
    }
    return re;
}

long long main()
{
    freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);

    long long n=0;
    long long lin=0;
    while (scanf("%c",&mapp[++n])!=EOF) {
        if (mapp[n]=='\n') {
            lin++;
        }
    }
    n--;
    long long num=dea(lin);
    long long x=1;
    for (long long i=1;i<=num-1;i++) std::cout<<" ";
    std::cout<<"1 ";
    
    for (long long i=1;i<=n;i++) {
        prlong longf("%c",mapp[i]);
        if (mapp[i]=='\n') {
            x++;
            // if (i==n) break;
            long long lls=dea(x);
            for (long long j=1;j<=(num-lls);j++) std::cout<<" ";
            std::cout<<x<<" ";
        }
    }

    return 0;
}