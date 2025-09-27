#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=100000;
long long fa[N+2],a[N+2],b[N+2],c[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n,tag=1;
        std::cin>>n;
        for (long long i=1;i<=n;i++) std::cin>>a[i]>>b[i]>>c[i];
        std::vector<long long> ls;
        for (long long i=1;i<=n;i++) {
            ls.push_back(a[i]);
            ls.push_back(b[i]);
        }
        std::sort(ls.begin(),ls.end());
        // for (long long i=0;i<(long long)ls.size();i++) std::cout<<ls[i]<<" ";
        // std::cout<<std::endl;
        long long len=std::unique(ls.begin(),ls.end())-ls.begin();  // 这里特别注意，vector在unique之后不会缩短，剩余的位置会被填上重复的数字 ，所以需要我们自己反会数组长度来进行操作，可以吧后面的位置直接进行pop_back
        // for (long long i=0;i<len;i++) std::cout<<ls[i]<<" ";
        // std::cout<<std::endl;
        for (long long i=1;i<=n;i++) {
            a[i]=lower_bound(ls.begin(),ls.begin()+len-1,a[i])-ls.begin()+1;  // lower_bound的格式要记住
            b[i]=lower_bound(ls.begin(),ls.begin()+len-1,b[i])-ls.begin()+1;
            // std::cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<std::endl;
        }
        for (long long i=1;i<=len;i++) fa[i]=i;  // 初始化长度为len不是n，这里要注意值域和定义域的转换
        for (long long i=1;i<=n;i++) {   // 这里通过调整顺序来简化算法复杂度，是一种离线操作
            if (!c[i]) continue;
            fa[find(a[i])]=find(b[i]);
        }
        for (long long i=1;i<=n;i++) {
            if (c[i]) continue;
            if (find(a[i])==find(b[i])) {
                tag=0;
                break;
            }
        }
        
        if (tag==0) std::cout<<"NO"<<std::endl;
        else std::cout<<"YES"<<std::endl;
    }

    return 0;
}