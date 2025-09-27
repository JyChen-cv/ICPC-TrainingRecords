#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

#define x first 
#define y second
const int N=1e3;
int n;
std::pair<int,int> mapp[N+2];

int gcd(int x,int y)
{
    return y? gcd(y,x%y) : x;
}

int main()
{
    int n;
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i].x;
    }
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i].y;
    }

    int tag=0,ans=0x3f3f3f3f;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (gcd(mapp[i].x,mapp[j].x)==1) {
                tag=1;
                ans=std::min(ans,mapp[i].y+mapp[j].y);
            }
        }
    }
    if (!tag) std::cout<<-1<<std::endl;
    else std::cout<<ans<<std::endl;
    return 0;
}