#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>

std::string s;
long long mapp[27];

long long main()
{
    std::cin>>s;
    long long tag1=0,ans=0x3f3f3f3f;
    for (long long i=0;i<(long long)s.size();i++) {
        if (s[i]<'a' || s[i]>'z') continue;
        mapp[s[i]-'a'+1]++;
        while (mapp[s[tag1]-'a'+1]>1) {
            mapp[s[tag1]-'a'+1]--;
            tag1++;
        }
        long long ls=0x3f3f3f3f;
        for (long long i=1;i<=26;i++) ls=std::min(ls,mapp[i]);
        if (ls>=1) ans=std::min(ans,i-tag1+1);
    }
    std::cout<<ans<<std::endl;

    return 0;
}