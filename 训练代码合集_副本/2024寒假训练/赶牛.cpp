#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

#define int long long
const int N = 1e5;
struct group {
	int x, y, tag;
	int p;
	bool operator < (const group& t) const {
		return p < t.p;
	}
} mapp[N + 2], mm[N + 2];
int n, m, k;
int fa[N + 2];
inline int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int deal(int x, int &cnt) {
	for (int i = 1; i <= m; i++) {
		mm[i] = mapp[i];
		if (mm[i].tag == 0) mm[i].p = mapp[i].p + x;
	}
	std::sort(mm + 1, mm + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	cnt = 0;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (find(mm[i].x) != find(mm[i].y)) {
			fa[find(mm[i].x)] = find(mm[i].y);
			if (mm[i].tag == 0) {
				cnt++;
				ans += mm[i].p - x;
			}
			else ans += mm[i].p;
		}
	}
	return ans;
}

signed main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		std::cin >> mapp[i].x >> mapp[i].y >> mapp[i].p >> mapp[i].tag;
		mapp[i].x++;
		mapp[i].y++;
	}
	int l = -111, r = 111;
	while (l < r) {
		int cnt = 0;
		int ans = 0;
		int mid = (l + r + 1) / 2;

		ans = deal(mid, cnt);
		int cntt = 0;
		deal(mid + 1, cntt);
		// std::cout << mid << " " << cnt << " " << cntt << " " << ans << " " << mm[1].tag << std::endl;
		if (cnt == k || (cnt > k && cntt < k)) {
			std::cout << ans << std::endl;
			break;
		}
		if (cnt < k) r = mid - 1;
		else l = mid;
	}
	return 0;
}