#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

const int N=100;
struct group {
    int num,q;
    bool operator < (const group &t)const {
        return q>t.q; // 这么大于号小于号拧这写有点扭曲。。。但是方便
    }
} mapp[N+2];
std::vector<int> can[N+2];

int gcd(int x,int y)
{
    return y ? gcd(y,x%y) : x;
}

bool deal (int x,int y)
{
    if (gcd(x,y)==1) return 1;
    else return 0;
}

int main()
{
    int n;
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i].num;
    }

    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (!deal(mapp[i].num,mapp[j].num)) {
                mapp[i].q++;
                mapp[j].q++;
            }
        }
    }
    std::sort(mapp+1,mapp+n+1); // 搜索的顺序很重要，比如这里的按“度”排序
    int num=1;
    for (int i=1;i<=n;i++) {
        int tagg=1;
        for (int j=1;j<=num;j++) {
            int tag=0;
            for (int k=0;k<(int)can[j].size();k++) {
                if (!deal(can[j][k],mapp[i].num)) tag=1;
            }
            if (tag==0) {
                can[j].push_back(mapp[i].num);
                tagg=0;
                break;
            }
        }
        if (tagg==1) {
            num++;
            can[num].push_back(mapp[i].num);
        }
    }
    std::cout<<num<<std::endl;
    return 0;
}