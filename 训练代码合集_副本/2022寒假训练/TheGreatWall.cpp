#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>

const long long N = 1000;
long long dp[N + 2][N + 2],mapp[N+2];
struct group {
	long long maxx;
	long long minn;
} p[N+2][N+2];

void deal(long long x, long long y)
{
    // std::cout<<mapp[x+1]<<" "<<p[x][y].maxx<<std::endl;
	if (mapp[x + 1] > p[x][y].maxx) {
		p[x + 1][y].maxx = mapp[x + 1];
		p[x + 1][y].minn = p[x][y].minn;
		// return mapp[x + 1] - p[x][y].maxx;
	}
	else if (mapp[x + 1] < p[x][y].minn) {
		p[x + 1][y].minn = mapp[x + 1];
		p[x + 1][y].maxx = p[x][y].maxx;
		// return p[x][y].minn - mapp[x + 1];
	}
    else {
    	p[x + 1][y].maxx = p[x][y].maxx;
	    p[x + 1][y].minn = p[x][y].minn;
    }
	// return 0;
}

long long obv(long long x,long long y)
{
    if (mapp[x+1]>p[x][y].maxx) return mapp[x + 1] - p[x][y].maxx;
    else if (mapp[x+1]<p[x][y].minn) return p[x][y].minn - mapp[x + 1];
    else return 0;
}

long long main()
{
	freopen("data.in", "r", stdin);
    freopen("ans.txt","w",stdout);
	long long n;
	std::cin >> n;

	for (long long i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		p[i][i].maxx = mapp[i];
		p[i][i].minn = mapp[i];
	}

	// memset(dp, 0, sizeof(dp));
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j < i; j++) {
			// dp[i][j] = std::max(dp[i - 1][j - 1], dp[i - 1][j] + xx(i-1,j));
            long long ls=dp[i-1][j]+obv(i-1,j);
            if (dp[i-1][j-1]<ls) {
                dp[i][j]=ls;
                deal(i-1,j);
            }
            else {
                dp[i][j]=dp[i-1][j-1];
                p[i][j].maxx=mapp[i];
                p[i][j].minn=mapp[i];
            }
		}
		dp[i][i] = 0;
        // std::cout<<p[3][2].maxx<<" ??? "<<p[3][2].minn<<" "<<obv(1,1)<<std::endl;
		// for (long long j = 1; j <= i; j++) std::cout << dp[i][j] << " ";
		// std::cout << std::endl;
	}
	for (long long i = 1; i <= n; i++) std::cout << dp[n][i] << std::endl;

	return 0;
}