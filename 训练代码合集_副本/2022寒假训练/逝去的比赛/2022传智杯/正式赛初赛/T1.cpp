#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

long long main()
{
    long long a,b;
    std::cin>>a>>b;
    if (b>0) std::cout<<std::abs(a)<<std::endl;
    else std::cout<<std::abs(a)*(-1)<<std::endl;

    return 0;
}