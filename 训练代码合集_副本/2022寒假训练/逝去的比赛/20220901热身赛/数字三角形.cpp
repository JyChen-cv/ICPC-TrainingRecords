#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

long long main()
{
    long long n,val=0;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=i;j++) {
            val++;
            prlong longf("%4d",val);
        }
        std::cout<<std::endl;
    }

    return 0;
}