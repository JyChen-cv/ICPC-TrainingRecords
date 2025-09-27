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

#define int long long
typedef long long lll;
typedef double db;
typedef std::pair<int, int> PII;

int len[30], n, m;
std::string q, ans;

std::string add(std::string a, std::string b) {
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	int l = std::max(a.size(), b.size()), tag = 0;
	std::string res;
	for (int i = 0; i < l; i++) {
		char now = tag;
		tag = 0;
		if (i < a.size()) now += a[i] - '0';
		if (i < b.size()) now += b[i] - '0';
		if (now > 9) tag = 1, now -= 10;
		res.push_back(now + '0');
	}
	if (tag) res .push_back('1');
	std::reverse(res.begin(), res.end());
	return res;
}

std::string cal() {
	int st = 0;
	std::string res;
	for (int i = 1; i <= m; i++) {
		std::string a = q.substr(st, len[i]);
		// std::cout << a << std::endl;
		res = add(res, a);
		// if (ans < res) return res;
		// std::cout << res << std::endl;
		st += len[i];
	}
	std::string a = q.substr(st);  // 默认直接到结尾
	res = add(res, a);
	return res;
}

bool operator<(std::string a, std::string b) {
	if (a.size() < b.size()) return 1;
	else if (a.size() > b.size()) return 0;
	else {
		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i] < b[i]) return 1;
			else if (a[i] > b[i]) return 0;
		}
		return 0;
	}
}

void dfs(int now, int lll) {
	// 还可以再加一个最优化剪枝
	if (lll >= n) return ;
	if (now == m + 1) {
		int ls = n - lll;
		if (std::abs(ls - len[m]) > 1) return ;
		std::string a = cal();
		// std::cout << a << std::endl;
		if (a < ans) ans = a;
		return ;
	}
	int l = n / (m + 1);
	if (l <= (int)ans.size() && (now <= 1 || std::abs(len[now - 1] - l) <= 1)) {
		len[now] = l;
		dfs(now + 1, l + lll);
	}
	if (l > 1 && l - 1 <= (int)ans.size() && (now <= 1 || std::abs(len[now - 1] - l + 1) <= 1)) {
		len[now] = l - 1;
		dfs(now + 1, lll + l - 1);
	}
	if (l + 1 <= (int)ans.size() && (now <= 1 || std::abs(len[now - 1] - l - 1) <= 1)) {
		len[now] = l + 1;
		dfs(now + 1, lll + l + 1);
	}
	if (l + 2 <= (int)ans.size() && (now <= 1 || std::abs(len[now - 1] - l - 2) <= 1)) {
		len[now] = l + 2;
		dfs(now + 1, lll + l + 2);
	}
}

void solve() {
	std::cin >> n >> m >> q;
	for (int i = 0; i <= m + 1; i++) len[i] = 0;
	ans = q;
	dfs(1, 0);
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}