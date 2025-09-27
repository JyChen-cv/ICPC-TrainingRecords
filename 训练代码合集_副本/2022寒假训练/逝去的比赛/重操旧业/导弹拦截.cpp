#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long MaxN=100000;
long long n=1,mapp[MaxN+2],d1[MaxN+2],d2[MaxN+2];

inline bool read(long long& x) {
    char c=getchar();
    if (c==EOF) return false;
    while (c>'9' || c<'0') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    // mapp[n]=x;
    return true;
}

long long main() {
    // freopen("okok.in","r",stdin);

    while (read(mapp[n])) {
        n++;
    }
    n--;
    // std::cout<<mapp[1]<<std::endl<<n<<std::endl;
    
    long long len1=1,len2=1;
    d1[len1]=mapp[1];
    d2[len2]=mapp[1];
    for(long long i=2;i<=n;i++) {
        if (d1[len1]>=mapp[i]) {
            len1++;
            d1[len1]=mapp[i];
        }
        else {
            long long tag1=std::upper_bound(d1+1,d1+1+len1,mapp[i],std::greater<long long>() )-d1;
            d1[tag1]=mapp[i];
        }
        if (d2[len2]<mapp[i]) {
            len2++;
            d2[len2]=mapp[i];
        }
        else {
            long long tag2=std::lower_bound(d2+1,d2+1+len2,mapp[i])-d2;
            d2[tag2]=mapp[i];
        }
    }

    std::cout<<len1<<std::endl<<len2<<std::endl;
    return 0;
}           //Dilworth定理