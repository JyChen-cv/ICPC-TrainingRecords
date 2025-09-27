#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

std::string mapp;
std::vector<long long> ls;
long long rem[8];
long long ans=0x3f3f3f3f3f3f3f3f;

void dfs(long long x,long long y)
{
    if (y==0) {
        ans=std::min(ans,x);
        return ;
    }
    for (long long i=1;i<(long long)ls.size();i++) {
        if (rem[i]==0) {
            rem[i]=1;
            dfs(x*100+ls[i],y-1);
            rem[i]=0;
        }
    }
}

long long main()
{
    for (long long i=1;i<=6;i++) {
        mapp.clear();
        std::cin>>mapp;
        if (mapp=="one") ls.push_back(1);
        else if (mapp=="two") ls.push_back(2);
        else if (mapp=="three") ls.push_back(3);
        else if (mapp=="four") ls.push_back(4);
        else if (mapp=="five") ls.push_back(5);
        else if (mapp=="six") ls.push_back(6);
        else if (mapp=="seven") ls.push_back(7);
        else if (mapp=="eight") ls.push_back(8);
        else if (mapp=="nine") ls.push_back(9);
        else if (mapp=="ten") ls.push_back(10);
        else if (mapp=="eleven") ls.push_back(11);
        else if (mapp=="twelve") ls.push_back(12);
        else if (mapp=="thriteen") ls.push_back(13);
        else if (mapp=="fourteen") ls.push_back(14);
        else if (mapp=="fifteen") ls.push_back(15);
        else if (mapp=="sixteen") ls.push_back(16);
        else if (mapp=="seventeen") ls.push_back(17);
        else if (mapp=="eighteen") ls.push_back(18);
        else if (mapp=="nineteen") ls.push_back(19);
        else if (mapp=="twenty") ls.push_back(20);
        else if (mapp=="a") ls.push_back(1);
        // else if (mapp=="another") ls.push_back(1);
    }
    mapp.clear();
    std::cin>>mapp;

    for (long long i=0;i<(long long)ls.size();i++) {
        ls[i]=ls[i]*ls[i];
        ls[i]%=100;
    }
    for (long long i=0;i<(long long)ls.size();i++) {
        rem[i]=1;
        dfs(ls[i],(long long)ls.size()-1);
        rem[i]=0;
    }

    if (ans!=0x3f3f3f3f3f3f3f3f) std::cout<<ans<<std::endl;
    else std::cout<<0<<std::endl;
    return 0;
}