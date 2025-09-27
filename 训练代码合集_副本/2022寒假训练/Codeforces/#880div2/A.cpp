#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

const int N=100;
int mapp[N+2];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        memset(mapp,0,sizeof(mapp));

        int n;
        std::cin>>n;
        for (int i=1;i<=n;i++) {
            int a;
            std::cin>>a;
            mapp[a]++;
        }
        int tag=0;
        for (int i=1;i<=100;i++) {
            if (mapp[i]) {
                if (mapp[i]>mapp[i-1]) tag=1;
            }
        }
        if (tag==0) std::cout<<"Yes"<<std::endl;
        else std::cout<<"No"<<std::endl;
    }
    return 0;
}