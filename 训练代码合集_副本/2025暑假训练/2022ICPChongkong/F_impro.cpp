#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
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

int len[10], n, m;
std::string q, ans, kong;
std::map<std::pair<int, int>, std::string> remb;

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

std::string dfs(int ed, int div, int lll) {
	// std::cout << ed << " " << div << " " << lll << std::endl;
	if (div == 1) {
		return q.substr(0, ed);
	}

	if (remb[ {ed, div}].size()) return remb[ {ed, div}];
	std::string res = q.substr(0, ed);
	std::string ls;
	if (lll <= res.size()) {
		ls = dfs(ed - lll, div - 1, lll);
		ls = add(ls, q.substr(ed - lll, lll));
		// std::cout << ls << std::endl;
		if (ls < res) res = ls;
	}
	if (lll - 1 <= res.size()) {
		lll--;
		ls = dfs(ed - lll, div - 1, lll);
		ls = add(ls, q.substr(ed - lll, lll));
		if (ls < res) res = ls;
		lll++;
	}
	if (lll + 1 <= res.size()) {
		lll++;
		ls = dfs(ed - lll, div - 1, lll);
		ls = add(ls, q.substr(ed - lll, lll));
		if (ls < res) res = ls;
		lll--;
	}

	return remb[ {ed, div}] = res;
}

void solve() {
	std::cin >> n >> m >> q;
	std::cout << dfs(n, m + 1, n / (m + 1)) << std::endl;
	// std::cout << ans << std::endl;
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