#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=26;
long long mapp[N+2];
std::string ll;

bool check(long long ls) {
    if (ls==0) return 0;
    else if (ls==1) return 0;
    for (long long i=2;i*i<=ls;i++) if (ls%i==0) return 0;
    return 1;
}

long long main()
{
    std::cin>>ll;
    for (long long i=0;i<(long long)ll.size();i++) mapp[ll[i]-'a'+1]++;
    long long ls1=0;
    long long ls2=0x3f3f3f3f;
    for (long long i=1;i<=26;i++) {
        ls1=std::max(ls1,mapp[i]);
        if (mapp[i]) ls2=std::min(ls2,mapp[i]);
    }
    long long ls=ls1-ls2;
    if (check(ls)) std::cout<<"Lucky Word"<<std::endl<<ls<<std::endl;
    else std::cout<<"No Answer"<<std::endl<<0<<std::endl;

    return 0;
}