#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>

const int N=20;
int mapp[N+2][N+2],v[N+2][N+2];
const int dx[5]={0,1,-1,0,0};
const int dy[5]={0,0,0,1,-1};

int main()
{
    int n,m,px,py;
    while (std::cin>>m>>n) {
        if (m==0 && n==0) break;
        memset (mapp,0,sizeof(mapp));
        memset (v,0,sizeof(v));

        for (int i=1;i<=n;i++) {
            std::string a;
            std::cin>>a;
            for (int j=0;j<(int)a.size();j++) {
                if (a[j]=='.') mapp[i][j+1]=1;
                else if (a[j]=='@') {
                    mapp[i][j+1]=1;
                    px=i;
                    py=j+1;
                }
            }
        }
        std::queue<std::pair<int,int> > q;
        q.push(std::make_pair(px,py));
        int tot=1;
        v[px][py]=1;
        while (q.size()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for (int i=1;i<=4;i++) {
                int xx=dx[i]+x;
                int yy=dy[i]+y;
                if (!mapp[xx][yy] || v[xx][yy]) continue;
                tot++;
                v[xx][yy]=1;
                q.push(std::make_pair(xx,yy));
            }
        }
        std::cout<<tot<<std::endl;
    }
    return 0;
}