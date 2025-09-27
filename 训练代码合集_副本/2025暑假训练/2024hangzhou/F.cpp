#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>
#include <bitset>

#define endl '\n'
#define ll long long
#define int long long
using namespace std;
int T;
int n, k, p;
int a[500000];
vector<int> b[500000];//强联通分量编号
vector<int> g[500000];

int tmp = 0;
int dfn[500000];
int low[500000];//子树中的节点经过至多一条非树边能到达的最小的dfs序
int stk[500000], s = 0;
int scc[500000], cnt = 0; //所属的强连通分量
int mark[500000];//记录是否在栈内
// vector<int> ans[500000];

void tarjan(int x)
{
	low[x] = dfn[x] = ++tmp;
	stk[++s] = x, mark[x] = 1;
	for (int q : g[x])
	{
		if (dfn[q] == 0) tarjan(q), low[x] = min(low[x], low[q]);
		if (mark[q]) low[x] = min(low[x], dfn[q]);
	}

	if (dfn[x] == low[x])
	{
		cnt++;
		while (1)
		{
			int z = stk[s];
			s--, mark[z] = 0; //出栈
			scc[z] = cnt;
			// ans[cnt].push_back(z);
			if (z == x) break;
		}
	}
}


int i = 0;

struct stt {
	ll l, r, sum, lx, rx, dl, dr;
};

vector<stt> t[500000];

stt update(stt sonl, stt sonr)
{
	stt z;
	z.l = sonl.l;
	z.r = sonr.r;
	z.sum = sonl.sum + sonr.sum;
	z.lx = sonl.lx;
	z.rx = sonr.rx;
	if (sonl.rx == sonr.lx)
	{
		int x = sonl.dr;
		int y = sonr.dl;
		// cout<<x<<" "<<y<<" "<<z.sum<<endl;
		z.sum -= (x) * (x - 1) / 2;
		// cout<<x<<" "<<y<<" "<<z.sum<<endl;
		z.sum -= (y) * (y - 1) / 2;
		// cout<<x<<" "<<y<<" "<<z.sum<<endl;
		z.sum += (x + y) * (x + y - 1) / 2;
	}

	z.dl = sonl.dl;
	if (sonl.lx == sonr.lx) z.dl += sonr.dl;

	z.dr = sonr.dr;
	if (sonl.rx == sonr.rx) z.dr += sonl.dr;

	return z;
}

void build(ll x, ll l, ll r) //默认 1,1,n
{
	t[i][x].l = l, t[i][x].r = r;
	if (l == r)
	{
		t[i][x].sum = 0;
		t[i][x].lx = t[i][x].rx = b[i][l];
		t[i][x].dl = t[i][x].dr = 1; //长度
		return;
	}
	ll mid = (l + r) / 2;
	build(2 * x, l, mid); build(2 * x + 1, mid + 1, r);

	t[i][x] = update(t[i][2 * x], t[i][2 * x + 1]);

	// cout<<i<<" "<<t[i][x].l<<" "<<t[i][x].r<<" "<<t[i][x].sum<<endl;
}

stt ask(ll x, ll l, ll r)
{
	if (t[i][x].l > r || t[i][x].r < l)
	{
		// cout<<
		return t[i][0];
	}
	if (t[i][x].l >= l && t[i][x].r <= r)
	{
		// cout<<i<<" "<<x<<endl;
		return t[i][x];
	}

	// cout<<update(ask(2*x,l,r),ask(2*x+1,l,r)).sum<<endl;

	return update(ask(2 * x, l, r), ask(2 * x + 1, l, r));
}

void solve()
{
	tmp = s = cnt = 0;
	cin >> n >> k >> p;
	for (int q = 1; q <= n; q++) g[q].clear(), dfn[q] = low[q] = scc[q] = mark[q] = 0;

	for (int q = 1; q <= k; q++) b[q].clear(), t[q].clear();

	// for(int q=1;q<=k;q++)

	for (int q = 1; q <= k; q++)
	{
		for (int w = 1; w <= n; w++) cin >> a[w];
		for (int w = 1; w < n; w++) g[a[w]].push_back(a[w + 1]);

		b[q].push_back(0);
		for (int w = 1; w <= n; w++) b[q].push_back(a[w]);
	}

	for (int q = 1; q <= n; q++) if (dfn[q] == 0) tarjan(q);

	// for(int q=1;q<=n;q++) cout<<scc[q]<<" ";
	// cout<<endl;

	for (int q = 1; q <= k; q++) for (int w = 1; w <= n; w++) b[q][w] = scc[b[q][w]];

	for (int q = 1; q <= k; q++) t[q].reserve(4 * n);
	// for(int q=1;q<=k;q++) for(int x:)

	for (int q = 1; q <= k; q++)
	{
		i = q;
		build(1, 1, n);
	}

	int v = 0;
	while (p--)
	{
		int id, l, r;
		cin >> id >> l >> r;

		// cout<<id<<" "<<l<<" "<<r<<endl;

		id = (id + v) % k + 1;
		l = (l + v) % n + 1;
		r = (r + v) % n + 1;

		// cout<<id<<" "<<l<<" "<<r<<endl;

		i = id;
		v = ask(1, l, r).sum;

		cout << v << endl;
	}
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
//freopen("a.txt","r",stdin);
//freopen("b.txt","w",stdout);
	cin >> T;
	while (T--) solve();

	return 0;
}







