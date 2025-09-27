#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

long long mapp[100005];
std::map<long long,long long> www;

long long deal(long long x)
{
    if (mapp[x]) return mapp[x];
    if (x<=0) return 0;
    if (x==1) return 0;
    if (x%2==1) {
        long long ls=deal((x-1)/2);
        long long lss=deal((x+1)/2);
        return mapp[x]=ls+lss+1;
    }
    else {
        long long ls=deal(x/2);
        return mapp[x]=ls*2;
    }
} 

long long deall(long long x)
{
    if (www[x]) return www[x];
    if (x==0) return 0;
    if (x==1) return 0;
    if (x%2==1) {
        long long ls=deall((x-1)/2);
        long long lss=deall((x+1)/2);
        return www[x]=ls+lss+1;
    }
    else {
        long long ls=deall(x/2);
        return www[x]=ls*2;
    }
}

long long main() 
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long a;
        scanf("%lld",&a);
        if (a>100000) {
            std::cout<<deall(a)<<std::endl;
        }
        else prlong longf("%d\n",deal((long long)a));
    }

    return 0;
}