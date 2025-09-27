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
    long long a=0,b=0;
    for (long long i=1;i<=n;i++) {
        scanf("%lld",&b);
        update(i,b-a);
        a=b;
    }

    for (long long i=1;i<=m;i++) {
        long long a;
        std::cin>>a;
        if (a==1) {
            long long b,c;
            long long d;
            scanf("%d%d%lld",&b,&c,&d);
            update(b,d);
            update(c+1,-d);
        }
        else {
            long long b;
            scanf("%d",&b);
            prlong longf("%lld\n",sum(b));
        }
    }

    return 0;
}