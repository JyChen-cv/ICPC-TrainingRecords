#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

const long long N=2*10000;
long long f[N+2];
struct group {
    long long v;
    long long w;
};
group q[3*10000+2];

long long main()
{
    long long n,m,lantans=0,tail=0;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        b^=lantans;
        c^=lantans;
        if (a==1) {
            tail++;
            q[tail].v=b;
            q[tail].w=c;
        }
        else if (a==2) {
            tail--;
        }
        else {
            memset (f,0,sizeof(f));
            for (long long i=1;i<=tail;i++) {
                for (long long j=std::min(b,m);j>=q[i].v;j--) {
                    f[j]=std::max(f[j],f[j-q[i].v]+q[i].w);
                }
            }
            lantans=f[b];
            std::cout<<lantans<<std::endl;
        }
    }

    return 0;
}