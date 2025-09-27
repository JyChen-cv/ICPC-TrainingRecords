#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        if (n%2==0) {
            for (long long i=n-(n/2);i<=n+(n/2);i++) {
                if (i!=n) std::cout<<i<<" ";
            }
            std::cout<<std::endl;
        }
        else {
            std::vector<long long> q;
            for (long long i=n-(n/2);i<=n+(n/2)-2;i++) {
                q.push_back(i+4);
            }
            q.push_back(n+(n/2)+4);
            q.push_back(n+(n/2)+7);
            for (long long i=0;i<(long long)q.size();i++) std::cout<<q[i]<<" ";
            std::cout<<std::endl;
        }
    }
    
    return 0;
}