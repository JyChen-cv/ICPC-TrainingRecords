#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=2000000;
long long mapp1[N+2],mapp2[N+2],fa[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        for (long long i=1;i<=n;i++) fa[i]=i;
        for (long long i=1;i<n;i++) {
            std::cin>>mapp1[i]>>mapp2[i];
        }
        long long tt=1,sum=1;
        while (1) {
            
            for (long long i=1;i<n;i++) {
                if (fa[mapp1[i]]==1 && fa[mapp2[i]]==1) continue;
                else if ((fa[mapp1[i]]!=1 && fa[mapp2[i]]!=1)) continue;
                else {
                    sum++;
                    fa[mapp1[i]]=1;
                    fa[mapp2[i]]=1;
                }
            }
            if (sum==n) {
                std::cout<<tt<<std::endl;
                break;
            }
            else tt++;
        }
    }
    return 0;
}