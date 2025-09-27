#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <set>
using namespace std;

using ll = long long;


void dp(vector<vector<int>>& res, vector<vector<int>>& ori, int a, int b , int c) {
	//if (c <= a) return;

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			if (i < a || j < b) res[i][j] = ori[i][j];
			else if (ori[i - a][j - b] != -1)
				res[i][j] = max(ori[i - a][j - b] + c - a, ori[i][j]);
			else
				res[i][j] = ori[i][j];
		}
	}

	ori = res;
};

void mearge(vector<vector<int>>& res, vector<vector<int>>& pre) {
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			res[i][j] = max(res[i][j], pre[i][j]);
		}
	}
}

class UnionFind {
public:
	UnionFind(int n)
		: parent(n + 1)
	{
		for (int i = 0; i <= n; i++) parent[i] = i;
	}

	void connect(int x, int y) {
		x = getParent(x), y = getParent(y);
		parent[x] = y;
	}

	int getParent(int x) {
		if (x != parent[x])
			parent[x] = getParent(parent[x]);
		return parent[x];
	}

	vector<int> parent;
};

void slove() {
	int n, m, v, x;
	cin >> n >> m >> v >> x;
	vector<int> a(n + 1); // 买入价
	vector<int> b(n + 1); // 重量
	vector<int> c(n + 1); // 卖出价

	int dfsn = 1;
	vector<int> vis(n + 1), mi(n + 1);

	vector<vector<int>> edges(n + 1);

	vector<set<int>> path(n + 1);
	vector<vector<int>> node(n + 1);

	vector<int> degree(n + 1);
	vector<int> inStack(n + 1);
	stack<int> s;

	vector<vector<vector<int>>> res(n + 1, vector<vector<int>>(m + 1, vector<int>(v + 1 , -1))); // 本金 ,重量
	vector<vector<vector<int>>> ori(n + 1, vector<vector<int>>(m + 1, vector<int>(v + 1, -1))); // 本金 ,重量
	for (int i = 1; i <= n; i++) res[i][0][0] = 0 , ori[i][0][0] = 0;
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		int t;
		cin >> t;
		int nx;
		while (t--) {
			cin >> nx;
			edges[i].emplace_back(nx);
		}
	}

	//UnionFind uf(n);
	function<void(int)> dfs = [&](int i) {
		vis[i] = dfsn++;
		mi[i] = vis[i];
		s.emplace(i);
		inStack[i] = true;

		for (auto nx : edges[i]) {
			if (vis[nx] && !inStack[nx]) continue;

			if (!vis[nx])
				dfs(nx);
			mi[i] = min(mi[i], mi[nx]);
		}

		if (vis[i] == mi[i]) {
			while (!s.empty() && vis[s.top()] >= vis[i]) {
				mi[s.top()] = mi[i];
				s.pop();
			}
		}

		inStack[i] = false;
	};

	dfs(x);
	// 连接强联通分量
	for (int i = 1; i < n; i++) {
		node[mi[i]].emplace_back(i);
		for (auto nx : edges[i]) {
			if (mi[nx] != mi[i])
				path[mi[i]].emplace(mi[nx]);
		}
	}

	for (int i = 1; i < n; i++) {
		if (node[i].size() != 0) {
			for (auto nx : path[i])
				degree[nx]++;
		}
	}

	queue<int> q;
	q.emplace(mi[1]);

	while (!q.empty()) {
		auto ptr = q.front();
		q.pop();

		for (int i = 0; i < node[ptr].size(); i++) {
			int tmp = node[ptr][i];
			dp(res[ptr], ori[ptr], a[tmp], b[tmp], c[tmp]);
		}

		for (auto nx : path[ptr]) {
			mearge(ori[nx], res[ptr]);
			degree[nx]--;
			if (degree[nx] == 0) q.emplace(nx);
		}
	}

	int ans = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= v; j++) {
			ans = max(ans, res[n][i][j]);
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 1;
	//cin >> cnt;

	while (cnt--) {
		slove();
	}

}