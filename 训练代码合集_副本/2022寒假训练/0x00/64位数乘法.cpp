#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

long long qd(long long a,long long b,long long c)
{
    if (b==0) return 0;
    if (b%2==1) return (qd(a,(b-1)/2,c)*2%c+a)%c;
    else return qd(a,b/2,c)*2%c;
}

long long main() 
{
    long long a,b,c;
    std::cin>>a>>b>>c;
    a%=c;
    b%=c;
    std::cout<<qd(a,b,c)<<std::endl;
    return 0;
}