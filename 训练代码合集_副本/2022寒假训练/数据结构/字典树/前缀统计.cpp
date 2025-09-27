#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=1000000;
long long trie[N+2][26],tot=1;
long long end[N+2];

void insert(char *str) {
    long long len=strlen(str),p=1;
    for (long long k=0;k<len;k++) {
        long long ch=str[k]-'a';
        if (trie[p][ch]==0) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
    end[p]++;
}

long long search(char *str) {
    long long len=strlen(str),p=1,res=0;
    for (long long k=0;k<len;k++) {
        p=trie[p][str[k]-'a'];
        res+=end[p];
    }
    return res;
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        char c[N+2];
        scanf("%s",c);
        insert(c);
    }
    for (long long i=1;i<=m;i++) {
        char c[N+2];
        scanf("%s",c);
        std::cout<<search(c)<<std::endl;
    }
    return 0;
}