#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>

const long long N=100000;
long long trie[32*N][2],tot=1;

void insert(long long val) {
    long long p=1;
    for (long long k=31;k>=0;k--) {
        long long ch=(val>>k)&1;
        if (trie[p][ch]==0) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
}

long long search(long long x) {
    long long p=1,res=0;
    for (long long i=31;i>=0;i--) {
        long long ch=(x>>i)&1;
        if (trie[p][ch^1]) {
            p=trie[p][ch^1];
            res<<=1;
            res+=ch^1;
        }
        else {
            p=trie[p][ch];
            res<<=1;
            res+=ch;
        }
    }
    return res;
}

long long main()
{
    long long n,ans=-1;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long a;
        std::cin>>a;
        insert(a);
        ans=std::max(ans,a^search(a));
    }
    std::cout<<ans<<std::endl;
    return 0;
}