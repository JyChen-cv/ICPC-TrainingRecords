#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        long long ans=0;
        while (n) {
            ans+=n;
            n/=2;
        }
        std::cout<<ans<<std::endl;
    }
    return 0; 
}