#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

const long long N=1e5;
long long head[700],nxt[N*2+5],ver[N*2+5],v[700],cnt[700];
double edge[N*2+5],d[700];
std::string c[N+2];
std::queue<long long> q;
long long n,tot;

void add(long long x,long long y,double c)
{
    edge[++tot]=c;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

bool spfa() {
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    for (long long i=1;i<=676;i++) {
        q.push(i);
        v[i]=1; // v就没必要赋值了
    }
    long long count=0;
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            double z=edge[i];
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                count++;
                if (count>=10000) return 1;
                cnt[y]=cnt[x]+1;
                if (cnt[y]>=676) return 1; // 不是>=n，因该是>=676！！！！！
                if (!v[y]) {
                    q.push(y);
                    v[y]=1;
                }
            }
        }
    }
    return 0;
}

inline long long deal(char a,char b) 
{
    return (a-'a')*26+(b-'a')+1;
}

bool check(double x)
{
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(ver,0,sizeof(ver));
    // memset(edge,0,sizeof(edge));
    tot=0;
    for (long long i=1;i<=n;i++) {
        long long len=c[i].size();
        add(deal(c[i][0],c[i][1]),deal(c[i][len-2],c[i][len-1]),(x*1-len));
    }
    return spfa();
}

long long main()
{
    while (std::cin>>n,n) {
        for (long long i=1;i<=n;i++) std::cin>>c[i];
        if (!check(0)) { //最坏情况下都没有负环，图中不会有负环 
            puts("No solution");
            continue;
        }
        double l=0,r=1000;
        while ((r-l)>0.0001) {
            double mid=(l+r)/2;
            if (check(mid)) l=mid;
            else r=mid;
        }
        prlong longf("%.2lf\n",l);
    }
    return 0;
}