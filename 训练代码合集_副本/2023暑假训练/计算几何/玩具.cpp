#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define x first
#define y second

typedef long long LL;
typedef std::pair<LL,LL> PLL;
const int N=5000;

int n,m,ans[N+2];
PLL a[N+2],b[N+2];

LL cross(LL x1,LL y1,LL x2,LL y2) {
    return x1*y2-x2*y1;
}

LL area(PLL a,PLL b,PLL c) {
    return cross(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

int find(LL x,LL y) {
    int l=0,r=n;
    while (l<r) {
        int mid=(l+r)/2;
        if (area(b[mid],a[mid],{x,y})>0) r=mid;
        else l=mid+1;
    }
    return r;
}

int main()
{
    bool is_first=true;
    while (scanf("%d",&n),n) {
        LL x1,y1,x2,y2;
        scanf("%d%lld%lld%lld%lld",&m,&x1,&y1,&x2,&y2);
        for (int i=0;i<n;i++) {
            LL u,l;
            scanf("%lld%lld",&u,&l);
            a[i]={u,y1};
            b[i]={l,y2};
        }
        a[n]={x2,y1};
        b[n]={x2,y2};
        
        if (is_first) is_first=false;
        else puts("");
        memset(ans,0,sizeof(ans));
        while (m--) {
            LL x,y;
            scanf("%lld%lld",&x,&y);
            ans[find(x,y)]++;
        }
        for (int i=0;i<=n;i++) {
            printf("%d: %d\n",i,ans[i]);
        }
    }

    return 0;
}