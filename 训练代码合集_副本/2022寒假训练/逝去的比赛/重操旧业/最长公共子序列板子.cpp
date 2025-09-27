#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

const long long MaxN=1000;
std::string s,t;
long long maxx,f[MaxN+2][MaxN+2];

long long main() {
    // freopen("okok.in","r",stdin);

    std::cin>>s>>t;
    long long len1=s.length();
    long long len2=t.length();

    for (long long i=1;i<=len1;i++) {
        for (long long j=1;j<=len2;j++) {
            f[i][j]=std::max(f[i-1][j],f[i][j-1]);
            if (s[i]==t[j]) f[i][j]=std::max(f[i][j],f[i-1][j-1]+1);
        }
    }

    std::cout<<f[len1][len2]<<std::endl;
    // std::cout<<len1<<" "<<len2<<std::endl;
    return 0;
}