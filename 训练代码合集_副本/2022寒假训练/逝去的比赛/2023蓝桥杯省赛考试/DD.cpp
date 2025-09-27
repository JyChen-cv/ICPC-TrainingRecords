#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=5000;
std::string mapp;
std::vector<long long> s;
bool f[N+2][N+2];

long long main()
{
    std::cin>>mapp;
    for (long long i=0;i<(long long)mapp.size();i++) {
        s.push_back(mapp[i]-'0'+1);
    }
    long long n=(long long)s.size();
    for (long long len=2;len<=n;len++) {
        for (long long l=0;l+len-1<n;l++) {
            long long r=l+len-1;
            if (s[l]>s[r]) f[l][r]=1;
            else if (s[l]==s[r]) {
                f[l][r]=f[l+1][r-1];
            }
        }
    }

    long long ans=0;
    for (long long i=0;i<n;i++) {
        for (long long j=i+1;j<n;j++) {
            if (f[i][j]) ans++;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}