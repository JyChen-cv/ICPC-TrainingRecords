#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

char sta[10],end[10];
std::vector<long long> sta_h,sta_m,end_h,end_m;

bool deal(char x,char y) {
    if (x==y) return 1;
    else if (y=='?') return 1;
    return 0;
}

bool check(long long x,long long y,char *p) {
    long long l=x%10;
    long long ll=((x-l)/10)%10;
    if (deal(l+'0',p[2]) && deal(ll+'0',p[1])) {
        l=y%10;
        ll=((y-l)/10)%10;
        if (deal(l+'0',p[5]) && deal(ll+'0',p[4])) return 1;
    }
    return 0;
}

long long main()
{
    scanf("%s",sta+1);
    scanf("%s",end+1);
    
    for (long long i=0;i<=23;i++) {
        for (long long j=0;j<=59;j++) {
            if (check(i,j,sta)) {
                sta_h.push_back(i);
                sta_m.push_back(j);
            }
            if (check(i,j,end)){
                end_h.push_back(i);
                end_m.push_back(j);
            }
        }
    }
    
    long long ans1=0x3f3f3f3f,ans2=-1;
    for (long long i=0;i<(long long)sta_h.size();i++) {
        for (long long j=0;j<(long long)end_h.size();j++) {
            long long ls=(end_h[j]-sta_h[i])*60+end_m[j]-sta_m[i];
            if (ls>0) {
                ans1=std::min(ans1,ls);
                ans2=std::max(ans2,ls);
            }
        }
    }
    // std::cout<<sta_h.size()<<" "<<end_h.size()<<std::endl;
    std::cout<<ans1<<" "<<ans2<<std::endl;
    
    return 0;
}