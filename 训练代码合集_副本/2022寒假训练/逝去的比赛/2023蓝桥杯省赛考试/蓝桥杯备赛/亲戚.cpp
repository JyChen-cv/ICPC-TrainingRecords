#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=20000;
long long fa[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m;
    scanf("%d%d",&n,&m);
    for (long long i=1;i<=n;i++) fa[i]=i;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        scanf("%d%d",&a,&b);
        fa[find(a)]=find(b);
    }
    scanf("%d",&m);
    for (long long i=1;i<=m;i++) {
        long long a,b;
        scanf("%d%d",&a,&b);
        a=find(a);
        b=find(b);
        if (a==b) prlong longf("Yes\n");
        else prlong longf("No\n");
    }
    return 0;
}