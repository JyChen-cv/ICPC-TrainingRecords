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

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 1e5;
const int B = 333;
int n, m, a[N + 2], b[N + 2], k[N + 2];
int pos[N + 2], L[N + 2], R[N + 2], top[N + 2], stk[N + 2];

void push(int p) {
	for (int i = L[p]; i <= R[p]; i++) {
		a[i] += b[p] + i * k[p];
	}
	b[p] = k[p] = 0;
}
inline int mul(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;  // 返回的是两个分数的差值
}
inline int mul(int x, int y, int z) {
	int x1 = y - z, y1 = a[y] - a[z];
	int x2 = x - z, y2 = a[x] - a[z];
	return mul(x1, y1, x2, y2);  // 返回的是y-z和x-z之间的斜率的差值
}

void rebuild(int p) {
	top[p] = L[p];  // 初始化栈顶
	for (int i = L[p]; i <= R[p]; i++) {
		while (top[p] >= L[p] + 2 && mul(stk[top[p] - 1], stk[top[p] - 2], i) >= 0) {
			// 保证不会越界，然后如果当前的斜率大于原本的斜率就弹出
			// 值得注意的是他比较的是 x-z和y-z，不是x-y和y-z这样常规情况
			top[p]--;
		}
		stk[top[p]++] = i;
	}
	// 非常巧妙的写法，这样每一段的答案就存在stk[]数组的top[p]位置中
}

void upd(int l, int r, int d) {
	push(pos[l]);
	for (int i = l; i <= R[pos[l]]; i++) {
		a[i] += std::min(r - l + 1, i - l + 1) * d;
	}
	for (int i = pos[l] + 1; i <= pos[n]; i++) {
		b[i] += (r - l + 1) * d;
	}
	rebuild(pos[l]);
}
void change(int l, int r, int d) {
	if (pos[l] == pos[r]) return upd(l, r, d); // 如果在一个块内直接暴力修改
	upd(l, R[pos[l]], d), upd(L[pos[r]], r, d); // 处理边角情况
	int len = 0;
	for (int i = pos[l] + 1; i <= pos[r] - 1; i++) {  // 整块的处理
		k[i] += d, b[i] -= d * R[pos[l]];
		len += (R[i] - L[i] + 1);  // len相当于是统计了长度，直接r-l+1???
	}
	for (int i = pos[r]; i <= pos[n]; i++) b[i] += len * d;
	// 感觉没有改全啊，还有最后区间加一个b的零碎没有处理吧？
}

inline int get(int i) {
	return a[i] + k[pos[i]] * i + b[pos[i]];
}
inline int get(int l, int r) {
	int res = -1e17;
	for (int i = l; i <= r; i++) {
		res = std::max(res, get(i));
	}
	return res;
}
int ask(int l, int r)
{
	if (pos[l] == pos[r]) return get(l, r);
	int res = std::max(get(l, R[pos[l]]), get(L[pos[r]], r));
	for (int i = pos[l] + 1; i <= pos[r] - 1; i++)
	{
		int r = top[i], cur = L[i];
		for (int j = 7; j >= 0; j--)
			if (cur + (1 << j) < r)
			{
				int nxt = cur + (1 << j);
				if (-k[i] * (stk[nxt] - stk[nxt - 1]) < a[stk[nxt]] - a[stk[nxt - 1]])
					cur = nxt;
			}
		res = std::max(res, get(stk[cur]));
	}
	return res;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
		pos[i] = (i - 1) / B + 1;
	}
	for (int i = 1; i <= n; i++) R[pos[i]] = i;  // 循环顺序保证了留下的是最后一个遍历到的值
	for (int i = n; i >= 1; i--) L[pos[i]] = i;  // 这么写很巧妙
	for (int i = 1; i <= pos[n]; i++) rebuild(i); // 一共就只有pos[n]个区间，每个区间的大小是B

	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int op, x, y, k;
		std::cin >> op;
		if (op) {
			std::cin >> x >> y;
			std::cout << ask(x, y) << std::endl;
		}
		else {
			std::cin >> x >> y >> k;
			change(x, y, k);
		}
	}

	return 0;
}