#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=100;
long long d[N+2],v[N+2];
std::vector<long long> mapp[N+2];
std::queue<long long> ans;

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long a;
        while (std::cin>>a,a) {
            mapp[i].push_back(a);
            d[a]++;
        }
    }
    
    for (long long i=1;i<=n;i++) 
        if (!d[i]) ans.push(i);
    while (ans.size()) {
        long long x=ans.front();
        std::cout<<(x)<<" ";
        ans.pop();
        for (long long i=0;i<(long long)mapp[x].size();i++) {
            d[mapp[x][i]]--;
            if (!d[mapp[x][i]]) ans.push(mapp[x][i]);
        }
    }
    return 0;
}