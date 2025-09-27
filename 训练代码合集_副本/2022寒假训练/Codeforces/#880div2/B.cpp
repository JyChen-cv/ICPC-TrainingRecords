#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        long long n,k,g;
        std::cin>>n>>k>>g;
        long long ls=(g-1)/2;
        if (n*ls>=k*g) {
            std::cout<<(k*g)<<std::endl;
        }
        else {
            long long lss=k*g-n*ls;
            long long tag=lss/g;
            if (lss%g) tag++;
            long long ans=k*g-tag*g;
            std::cout<<ans<<std::endl;
        }
    }
    return 0;
}