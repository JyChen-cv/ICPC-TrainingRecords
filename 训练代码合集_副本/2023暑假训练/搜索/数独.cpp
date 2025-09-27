#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

std::string a;
int mapp[10][10],tag;
struct group {
    int x,y,pro;
    bool operator < (const group &t)const {
        return pro<t.pro;
    }
} pa[100];

void dfs(int x)
{
    if (tag) return ;
    if (x>81) {
        for (int i=1;i<=9;i++) {
            for (int j=1;j<=9;j++) std::cout<<mapp[i][j];
        }
        tag=1;
        return ;
    }
    if (pa[x].pro==0) {
        dfs(x+1);
        return ;
    }

    int xx=pa[x].x;
    int yy=pa[x].y;
    int v[10];
    memset(v,0,sizeof(v));
    for (int k=1;k<=9;k++) {
        v[mapp[xx][k]]=1;
    }
    for (int k=1;k<=9;k++) {
        v[mapp[k][yy]]=1;
    }
    int qi=(xx-1)/3*3;
    int qj=(yy-1)/3*3;
    for (int k=1;k<=3;k++) {
        for (int l=1;l<=3;l++) {
            v[mapp[qi+k][qj+l]]=1;
        }
    }
    for (int i=1;i<=9;i++) {
        if (!v[i]) {
            mapp[xx][yy]=i;
            dfs(x+1);
            mapp[xx][yy]=0; // 为啥一定得回溯???
        }
    }
}

int main()
{
    while (std::cin>>a) {
        memset(pa,0,sizeof(pa));

        tag=0;
        if (a.size()!=81) break;
        for (int i=0;i<=8;i++) {
            for (int j=0;j<=8;j++) {
                if (a[i*9+j]=='.') {
                    mapp[i+1][j+1]=0;
                }
                else mapp[i+1][j+1]=a[i*9+j]-'0';
                std::cout<<mapp[i+1][j+1]<<" ";
            }
            std::cout<<std::endl;
        }
        for (int i=1;i<=9;i++) {
            for (int j=1;j<=9;j++) {
                int ls=(i-1)*9+j;
                pa[ls].x=i;
                pa[ls].y=j;

                if (mapp[i][j]) continue;
                int v[10];
                memset(v,0,sizeof(v));

                for (int k=1;k<=9;k++) {
                    v[mapp[i][k]]=1;
                }
                for (int k=1;k<=9;k++) {
                    v[mapp[k][j]]=1;
                }
                int qi=(i-1)/3*3;
                int qj=(j-1)/3*3;
                for (int k=1;k<=3;k++) {
                    for (int l=1;l<=3;l++) {
                        v[mapp[qi+k][qj+l]]=1;
                    }
                }
                for (int k=1;k<=9;k++) {
                    if (!v[k]) {
                        pa[ls].pro++;
                    }
                }
            }
        }
        std::sort(pa+1,pa+82);
        // for (int i=1;i<=81;i++) std::cout<<pa[i].x<<" "<<pa[i].y<<" "<<pa[i].pro<<std::endl;

        dfs(1);
    }
    return 0;
}