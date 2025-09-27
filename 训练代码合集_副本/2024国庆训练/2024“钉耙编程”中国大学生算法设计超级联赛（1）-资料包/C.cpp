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

#define int unsigned long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 5e5, M = 5e5, MAX = 1e6;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], tot;
int n, A[N + 2], sz[N + 2], hson[N + 2];
int cnt[MAX + 2], sm[MAX + 2], sm2[MAX + 2], ans[N + 2];
int Hson, nfa;

void add_edge(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int lowbit(int x) {
	return x & (-x);
}
void add(int p, int x, int *v) {
	while (p <= MAX) { // 开全局变量n
		v[p] += x;
		p += lowbit(p);
	}
}
int query(int p, int *v) {
	int res = 0;
	while (p) {
		res += v[p];
		p -= lowbit(p);
	}
	return res;
}
int sum(int l, int r, int *v) {
	if (l > r) std::swap(l, r);
	return query(r, v) - query(l - 1, v);
}

void dfs(int x, int fa) {
	sz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
		if (sz[y] > sz[hson[x]]) hson[x] = y;  // 不为0就是说明有重节点，就是说明不是叶子节点
	}
}
void contribution(int val) {
	int res_c = query(val, cnt), res_s = query(val, sm);
	int res_ss = sum(val + 1, MAX, sm), res_s2 = sum(val + 1, MAX, sm2);
	int res = res_c * val * val - res_s * val;  // 前缀贡献
	res += res_s2 - res_ss * val;  // 后缀贡献
	// std::cout << nfa << " : " << res_c << " " << res_s << " " << res_ss << " " << res_s2 << " " << res << std::endl;
	ans[nfa] += res;
}
void calc(int x, int fa, int op) {
	if (op == 1) {
		contribution(A[x]);  // 其实这里无所谓先后顺序，因为自己和自己是0
		add(A[x], 1, cnt), add(A[x], A[x], sm), add(A[x], (int)A[x]*A[x], sm2);
	}
	else {
		add(A[x], -1, cnt), add(A[x], -A[x], sm), add(A[x], -(int)A[x]*A[x], sm2);
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa || y == Hson) continue;
		calc(y, x, op);
	}
}
void dsu(int x, int fa, int op) {
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa || y == hson[x]) continue;
		dsu(y, x, 0);
	}
	if (hson[x]) {
		dsu(hson[x], x, 1), Hson = hson[x];  // 感觉放出去也没错
		// 先搜索然后再赋值，因为是全局变量，定义现在情况下的重儿子
		ans[x] += ans[hson[x]];  // 传递重儿子的贡献
	}
	nfa = x;  // 定义现在正在计算的是谁的贡献，当前处理的是哪个节点
	calc(x, fa, 1); // 再次便利亲儿子统计答案
	// 在这里计算答案

	// 计算完成，开始准备按照op回溯
	Hson = 0;
	if (!op) {  // 处理轻儿子
		calc(x, fa, 0); // 这里开0进行清理
		// 此处清理其他全局变量，重儿子是不用清理的，只有轻儿子需要被清理
	}
}
void solve() {
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add_edge(a, b), add_edge(b, a);  // 小心重名，和建立图的add函数撞了
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> A[i];
	}
	dfs(1, 0);
	dsu(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		// std::cout << i << ": " << ans[i] << std::endl;
		ans[i] ^= ans[i - 1];
	}
	std::cout << ans[n] * 2 << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}