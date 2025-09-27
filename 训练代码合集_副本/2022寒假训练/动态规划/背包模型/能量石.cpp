#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=10000;
struct group {
    long long s;  //时间
    long long e;  //能量
    long long l;  //每一秒消耗d能量
} mapp[N+2];
long long f[N+2],n;

bool cmp(group x,group y)
{
    return x.s*y.l<y.s*x.l;
}

long long main()
{
    long long t,tt=0;
    std::cin>>t;
    while (1) {
        tt++;
        if (tt>t) break;

        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i].s>>mapp[i].e>>mapp[i].l;
        }
        std::sort(mapp+1,mapp+n+1,cmp);
        memset (f,0,sizeof(f));
        
        for (long long i=1;i<=n;i++) {
            for (long long j=10001;j>=mapp[i].s;j--) {
                f[j]=std::max(f[j],f[j-mapp[i].s]+std::max(0,mapp[i].e-mapp[i].l*(j-mapp[i].s)));
            }
        }
        long long ans=0;
        for (long long i=1;i<=10001;i++) ans=std::max(ans,f[i]);
        std::cout<<"Case #"<<tt<<": "<<ans<<std::endl;
    }

    return 0;
}

//有一个启发就是：面对这种时间啊之类的全局都会跟着改变的东西，怎样去合理维护呢？
//要么就是改变自己，来相对看出别人的改变，这样能改变的较少
//要么就用一个优秀的数据结构，满足这种范围性的改变（差分。。。）
//要么就通过某种排序，确定自己的顺序就是最优秀的，这样就不存在顺序的问题了，只存在选还是不选的问题

//启发2:可以用调整法？来证明，例如这道题目
//i和i+1这两件物品
//若先选择i，则总能量为   e(i)+e(i+1)-s(i)*l(i+1);
//若先选择i+1，则总能量为 e(i+1)+e(i)-s(i+1)*l(i);
//那么现在对比，则可以进行排序