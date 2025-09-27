#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        std::vector<long long> ans;
        for (long long i=1;i<=n;i++) {
            if (i%2==1) ans.push_back(i+1);
            else ans.push_back(i-1);
        }
        if (n%2==1) {
            std::cout<<-1<<std::endl;
            continue;
        }
        for (long long i=0;i<(long long)ans.size();i++) {
            std::cout<<ans[i]<<" ";
        }
        std::cout<<std::endl;
        // for (long long len=2;len<=(long long)ans.size();len++) {
        //     for (long long i=0;i+len-1<(long long)ans.size();i++) {
        //         long long j=i+len-1;
        //         long long sum=0;
        //         for (long long k=i;k<=j;k++) {
        //             sum+=ans[k];
        //         }
        //         if (sum%len==0) std::cout<<len<<" "<<i<<" "<<j<<" "<<sum<<std::endl;
        //     }
        // }
    }
    return 0;
}