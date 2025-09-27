#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long MaxN=1000;
long long n,d1[MaxN+2],d2[MaxN+2],ans1[MaxN+2],mapp[MaxN+2],ans2[MaxN+2];

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

    read(n);
    for (long long i=1;i<=n;i++) {
        read(mapp[i]);
    }

    long long len1=1;
    d1[len1]=mapp[1];
    ans1[1]=len1;
    for (long long i=2;i<=n;i++) {
        if (d1[len1]<mapp[i]) {
            len1++;
            d1[len1]=mapp[i];
        }
        else {
            long long tag1=0;
            tag1=std::lower_bound(d1+1,d1+len1+1,mapp[i])-d1;
            d1[tag1]=mapp[i];
        }
        ans1[i]=len1;
    }
    long long len2=1;
    d2[len2]=mapp[n];
    ans2[n]=len2;
    for (long long i=n-1;i>=1;i--) {
        if (d2[len2]<mapp[i]) {
            len2++;
            d2[len2]=mapp[i];
        }
        else {
            long long tag2=0;
            tag2=std::lower_bound(d2+1,d2+len2+1,mapp[i])-d2;
            d2[tag2]=mapp[i];
        }
        ans2[i]=len2;
    }
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        ans=std::max(ans,ans1[i]+ans2[i]-1);
    }

    std::cout<<n-ans<<std::endl;
    return 0;
}