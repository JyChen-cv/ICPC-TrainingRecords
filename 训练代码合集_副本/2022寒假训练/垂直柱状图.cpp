#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=26;
long long mapp[N+2];

long long main()
{
    freopen("data.in","r",stdin);

    char c;
    while ((c=getchar())!=EOF) {
        if (c<='Z' && c>='A') {
            mapp[c-'A'+1]++;
        }
    }

    long long ls=0;
    for (long long i=1;i<=26;i++) {
        ls=std::max(ls,mapp[i]);
    }
    for (long long i=1;i<=ls;i++) {
        for (long long j=1;j<=26;j++) {
            if (i>(ls-mapp[j])) std::cout<<"*";
            else std::cout<<" ";
            if (j!=26) std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    for (long long i=1;i<=25;i++) prlong longf("%c ",(i+'A'-1));
    std::cout<<"Z"<<std::endl;

    return 0;
}