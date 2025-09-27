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
const int N=1e5;
int n,dep[N+2],tag;
std::pair<int,int> mapp[N+2];

void dfs(int x,int t)
{
    if (t<x) {
        if (!mapp[x].x) {
            if (!tag) mapp[x].x=t;
            dep[t]=dep[x]+1;
            if (tag) std::cout<<dep[t]<<std::endl;
        }
        else {
            dfs(mapp[x].x,t);
        }
    }
    else {
        if (!mapp[x].y) {
            if (!tag) mapp[x].y=t;
            dep[t]=dep[x]+1;
            if (tag) std::cout<<dep[t]<<std::endl;
        }
        else {
            dfs(mapp[x].y,t);
        }
    }
}

int main()
{
    std::cin>>n;
    for (int i=1;i<=n*2;i++) {
        int a;
        std::cin>>a;
        if (i>n) tag=1;
        else tag=0;
        dfs(0,a);
    }
    return 0;
}