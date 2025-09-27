#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

std::map<long long,std::map<long long,std::map<long long,std::map<long long,std::map<long long,long long> > > > > f;
long long num[6];

long long main()
{
    while (1) {
        long long k,all=0;
        std::cin>>k;
        if (k==0) break;
        for (long long i=1;i<=5;i++) {
            if (i<=k) std::cin>>num[i];
            else num[i]=0;
            all+=num[i];
        }

        f.clear();
        f[0][0][0][0][0]=1;
        // for (long long i=1;i<=all;i++) {
            for (long long j1=1;j1<=num[1];j1++) {
                for (long long j2=0;j2<=num[2] && j2<=j1;j2++) {
                    for (long long j3=0;j3<=num[3] && j3<=j2;j3++) {
                        for (long long j4=0;j4<=num[4] && j4<=j3;j4++) {
                            for (long long j5=0;j5<=num[5] && j5<=j4;j5++) {
                                f[j1][j2][j3][j4][j5]+=f[j1-1][j2][j3][j4][j5];
                                if (j2) f[j1][j2][j3][j4][j5]+=f[j1][j2-1][j3][j4][j5];
                                if (j3) f[j1][j2][j3][j4][j5]+=f[j1][j2][j3-1][j4][j5];
                                if (j4) f[j1][j2][j3][j4][j5]+=f[j1][j2][j3][j4-1][j5];
                                if (j5) f[j1][j2][j3][j4][j5]+=f[j1][j2][j3][j4][j5-1];
                                // std::cout<<j1<<" "<<j2<<" "<<j3<<" "<<j4<<" "<<j5<<" "<<f[j1][j2][j3][j4][j5]<<std::endl;
                            }
                        }
                    }

                }
            }
        // }

        std::cout<<f[num[1]][num[2]][num[3]][num[4]][num[5]]<<std::endl;
    }

    return 0;
}