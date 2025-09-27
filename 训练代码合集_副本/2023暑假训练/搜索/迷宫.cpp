#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

const int N=100;
const int dx[5]={0,1,-1,0,0};
const int dy[5]={0,0,0,1,-1};
int mapp[N+2][N+2],v[N+2][N+2];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        memset(v,0,sizeof(v));
        memset(mapp,0,sizeof(mapp));
        
        int n;
        std::cin>>n;
        for (int i=1;i<=n;i++) {
            std::string a;
            std::cin>>a;
            for (int j=0;j<(int)a.size();j++) { // 注意j的范围改变了
                if (a[j]=='.') mapp[i][j+1]=0;
                else mapp[i][j+1]=1;
                // std::cout<<mapp[i][j+1]<<" ";
            }
            // std::cout<<std::endl;
        }

        int px,py,ex,ey;
        std::cin>>px>>py>>ex>>ey;
        px++,py++,ex++,ey++;
        // std::cout<<px<<" "<<py<<std::endl;
        if (mapp[px][py] || mapp[ex][ey]) {
            std::cout<<"NO"<<std::endl;
            continue;
        }
        else if (px==ex && py==ey) {
            std::cout<<"YES"<<std::endl;
            continue;
        }
        std::queue<std::pair<int,int> > q;
        q.push(std::make_pair(px,py));
        int tag=1;
        while (q.size()) {
            int x=q.front().first;
            int y=q.front().second;
            // std::cout<<x<<" "<<y<<" "<<mapp[x][y]<<std::endl;
            q.pop();
            for (int i=1;i<=4;i++) {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (xx<1 || xx>n || yy<1 || yy>n) continue;
                if (v[xx][yy]) continue;
                if (mapp[xx][yy]) continue;
                v[xx][yy]=1;
                q.push(std::make_pair(xx,yy));
                if (ex==xx && ey==yy) {
                    tag=0;
                    break;
                }
            }
            if (tag==0) break;
        }
        if (tag==1) std::cout<<"NO"<<std::endl;
        else std::cout<<"YES"<<std::endl;
    }
    return 0;
}