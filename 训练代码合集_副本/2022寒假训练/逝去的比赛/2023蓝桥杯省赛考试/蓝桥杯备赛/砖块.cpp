#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

const long long N=200;
char mapp[N+2];

inline char deal(char c)
{
    if (c=='B') return 'W';
    else return 'B';
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        long long cnt_w=0,cnt_b=0;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
            if (mapp[i]=='W') cnt_w++;
            else cnt_b++;
        }

        if (cnt_b%2==1 && cnt_w%2==1) {
            std::cout<<-1<<std::endl;
            continue;
        }
        else {
            if (cnt_w==0 || cnt_b==0) {
                std::cout<<0<<std::endl;
                continue;
            }
            std::vector<long long> ans;
            if (cnt_w%2==0) {
                for (long long i=1;i<n;i++) {
                    if (mapp[i]!='B') {
                        ans.push_back(i);
                        mapp[i+1]=deal(mapp[i+1]);
                    }
                }
            }
            else {
                for (long long i=1;i<n;i++) {
                    if (mapp[i]!='W') {
                        ans.push_back(i);
                        mapp[i+1]=deal(mapp[i+1]);
                    }
                }
            }
            std::cout<<ans.size()<<std::endl;
            for (long long i=0;i<(long long)ans.size();i++) {
                std::cout<<ans[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    return 0;
}