#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        std::vector<long long> mapp;
        for (long long i=1;i<=n*n;i++) {
            if (i%2==0) mapp.push_back(i/2);
            else mapp.push_back(n*n-i/2);
        }
        long long tag=0;
        for (long long i=1;i<=n;i++) {
            std::vector<long long> prlong long;
            if (i%2==1) 
                for (long long j=1;j<=n;j++) {
                    std::cout<<mapp[tag]<<" ";
                    tag++;
                }
            else {
                for (long long j=n;j>=1;j--) {
                    prlong long.push_back(mapp[tag]);
                    tag++;
                }
                for (long long j=(long long)prlong long.size()-1;j>=0;j--) {
                    std::cout<<prlong long[j]<<" ";
                }
            }
            std::cout<<std::endl;
        }
    }
 
    return 0;
}