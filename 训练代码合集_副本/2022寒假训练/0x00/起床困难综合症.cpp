#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long MaxN=100000;
std::pair<std::string,long long> mapp[MaxN+5];
long long n,m;

long long calc(long long bit,long long now) 
{
    for (long long i=1;i<=n;i++) {
        long long x=mapp[i].second;
        x>>=bit;
        x&=1;
        if (mapp[i].first=="AND") {
            now&=x;
        }
        else if (mapp[i].first=="OR") {
            now|=x;
        }
        else now^=x;
    }
    return now;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        char str[5];
        long long x;
        scanf("%s%d",str,&x);
        mapp[i]=std::make_pair(str,x);
    }

    long long val=0,ans=0;
    for (long long bit=29;bit>=0;bit--) {
        long long res0=calc(bit,0);
        long long res1=calc(bit,1);
        if (res0<res1 && val+(1<<bit)<=m) {
            val+=1<<bit;
            ans+=res1<<bit;
        } 
        else ans+=res0<<bit;
    }
    std::cout<<ans<<std::endl;

    return 0;
}