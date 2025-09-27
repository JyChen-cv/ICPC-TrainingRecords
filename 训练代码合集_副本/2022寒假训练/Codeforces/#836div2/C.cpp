#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=200000;
bool mapp[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n,m;
        std::cin>>n>>m;
        if (n%m!=0) std::cout<<-1<<std::endl;
        else {
            memset(mapp,0,sizeof(mapp));
            std::vector<long long> q;
            std::queue<long long> ans;
            q.push_back(1);
            long long div=n/m;
            for (long long i=2;i*i<=div;i++) {
                while (div%i==0) {
                    div/=i;
                    q.push_back(i);
                }
            }
            if (div!=1) q.push_back(div);
            long long mm=m;
            for (long long i=0;i<(long long)q.size();i++) {
                mm*=q[i];
                mapp[mm]=1;
                ans.push(mm);
            }
            ans.pop();
            std::cout<<m<<" ";
            for (long long i=2;i<n;i++) {
                if (!mapp[i]) std::cout<<i<<" ";
                else {
                    std::cout<<ans.front()<<" ";
                    ans.pop();
                }
            }
            std::cout<<1<<std::endl;
        }
    }
    return 0;
}