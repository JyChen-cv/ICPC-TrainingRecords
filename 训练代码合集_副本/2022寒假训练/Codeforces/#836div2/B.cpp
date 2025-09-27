#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        if (n%2==1) {
            for (long long i=1;i<=n;i++) std::cout<<7<<" ";
            std::cout<<std::endl;
        }
        else {
            std::cout<<1<<" "<<3<<" ";
            // long long ls=(2*n-4)/(n-2)=2;
            for (long long i=1;i<=(n-2);i++) {
                std::cout<<2<<" ";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}