#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=100000;
long long BIT[N+2],BITT[N+2];
long long n,m;

long long lowbit(long long n)
{
    return n&(-n);
}

void update(long long x,long long y)
{
    long long ls=x;
    while (x<=n) {
        BIT[x]+=y;
        BITT[x]+=(ls-1)*y;
        x+=lowbit(x);
    }
}

long long sum(long long x)
{
    long long ans=0,ls=x;
    while (x) {
        ans+=BIT[x]*ls;
        ans-=BITT[x];
        x-=lowbit(x);
    }
    return ans;
}

long long main()
{
    std::cin>>n>>m;
    long long a=0,b=0;
    for (long long i=1;i<=n;i++) {
        scanf("%lld",&b);
        update(i,b-a);
        a=b;
    }

    for (long long i=1;i<=m;i++) {
        char a;
        std::cin>>a;
        if (a=='C') {
            long long b,c;
            long long d;
            scanf("%d%d%lld",&b,&c,&d);
            update(b,d);
            update(c+1,-d);
        }
        else {
            long long b,c;
            scanf("%d%d",&b,&c);
            prlong longf("%lld\n",sum(c)-sum(b-1));
        }
    }

    return 0;
}