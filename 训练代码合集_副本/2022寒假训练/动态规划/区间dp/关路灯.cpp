// https://www.luogu.com.cn/problem/P1220

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
const long long MaxN=100;
struct group{
	long long lengh;
	long long power;
} a[MaxN+5];
long long p[MaxN+5],w[MaxN+5][MaxN+5],f[MaxN+5][MaxN+5][2];

bool cmp(group x,group y)
{
	return x.lengh<y.lengh;
}

long long main()
{
	long long n,now;
	cin>>n>>now;
	for (long long i=1;i<=n;i++) {
		cin>>a[i].lengh>>a[i].power;
	}
	for (long long i=1;i<=n;i++) if (i!=now) a[i].lengh=(a[i].lengh-a[now].lengh);
	a[now].lengh=0;
	for (long long i=1;i<=n;i++) {
		p[i]=p[i-1]+a[i].power;
	}
	for (long long i=1;i<=n;i++) {
		for (long long j=i;j<=n;j++) {
			w[i][j]=p[n]-(p[j]-p[i-1]);
		}
	}  //预处理内容 
	
	memset (f,0x3f,sizeof(f));
    // 这的题目永远不会出现两块关掉的灯
	for (long long i=1;i<=n;i++) {
		f[i][i][0]=f[i][i][1]=abs(a[i].lengh)*p[n];
	}
	for (long long len=2;len<=n;len++) {
		for (long long l=1;l+len-1<=n;l++) {
			long long r=l+len-1;
			f[l][r][0]=min(f[l+1][r][0]+(a[l+1].lengh-a[l].lengh)*w[l+1][r],f[l][r][0]);
			f[l][r][0]=min(f[l+1][r][1]+(a[r].lengh-a[l].lengh)*w[l+1][r],f[l][r][0]);
			
			f[l][r][1]=min(f[l][r-1][1]+(a[r].lengh-a[r-1].lengh)*w[l][r-1],f[l][r][1]);
			f[l][r][1]=min(f[l][r-1][0]+(a[r].lengh-a[l].lengh)*w[l][r-1],f[l][r][1]);
		}
	}
	
	cout<<min(f[1][n][0],f[1][n][1])<<endl;
	return 0;
}