#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=500000;
long long BIT[N+2];
long long n,m;

long long lowbit(long long n)
{
    return n&(-n);
}

void update(long long x,long long y)
{
    while (x<=n) {
        BIT[x]+=y;
        x+=lowbit(x);
    }
}

long long sum(long long x)
{
    long long ans=0;
    while (x) {
        ans+=BIT[x];
        x-=lowbit(x);
    }
    return ans;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        long long a;
        scanf("%lld",&a);
        update(i,a);
    }

    for (long long i=1;i<=m;i++) {
        long long a;
        std::cin>>a;
        if (a==1) {
            long long b;
            long long c;
            scanf("%d%lld",&b,&c);
            update(b,c);
        }
        else {
            long long b,c;
            scanf("%d%d",&b,&c);
            prlong longf("%lld\n",sum(c)-sum(b-1));
        }
    }

    return 0;
}