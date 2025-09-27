#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

const long long MaxN=10000000;
long long m,n,f[MaxN+5],t[MaxN+5],v[MaxN+5];

inline bool read(long long& x) {
    char c=getchar();
    if (c==EOF) return 0;
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return 1;
}

long long main() {
    // freopen("okok.in","r",stdin);

    read(m);
    read(n);
    for (long long i=1;i<=n;i++) {
        read(t[i]);
        read(v[i]);
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=t[i];j<=m;j++) {
            f[j]=std::max(f[j],f[j-t[i]]+v[i]);
        }
    }

    std::cout<<f[m]<<std::endl;
    return 0;
}