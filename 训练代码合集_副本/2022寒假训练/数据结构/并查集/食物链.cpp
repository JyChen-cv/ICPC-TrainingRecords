#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=50000;
long long fa[N*3+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m,ans=0;
    std::cin>>n>>m;
    for (long long i=1;i<=n*3;i++) fa[i]=i;
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (c>n || b>n) ans++;
        else {
            long long l=find(b);
            long long k=find(c);
            long long ll=find(b+n);
            long long kk=find(c+n);
            long long lll=find(b+n*2);
            long long kkk=find(c+n*2);
            if (a==1) {
                if (l==kk || k==ll) ans++;
                else {
                    fa[l]=k;
                    fa[ll]=kk;
                    fa[lll]=kkk;
                }
            }
            else {
                if (l==k || l==kk) ans++;
                else {
                    fa[ll]=k;
                    fa[lll]=kk;
                    fa[l]=kkk;
                }
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}