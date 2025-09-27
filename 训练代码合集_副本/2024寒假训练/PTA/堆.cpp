#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 200001;
std::vector<char> ans;
int mapp[N + 2], tr[N + 2], ini[N + 2];

int read(std::string mp, int &point) {
	int tag = 1;
	if (mp[point] == '-') {
		tag = -1;
		point++;
	}
	int res = 0;
	while (point < (int)mp.size() && mp[point] <= '9' && mp[point] >= '0') {
		res *= 10;
		res += mp[point] - '0';
		point++;
	}
	return res * tag + 10001;
}

void deal(int p) {
	int fa = p / 2;
	if (fa == 0) return ;
	if (tr[fa] > tr[p]) {
		std::swap(tr[fa], tr[p]);
		deal(fa);
	}
}
void insert(int p, int x) {
	tr[p] = x;
	deal(p);
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] += 10001;
		insert(i, mapp[i]);
	}
	for (int i = 1; i <= n; i++) {
		ini[tr[i]] = i;
		// std::cout << tr[i] << " ";
	}
	// std::cout << ini[23] << " ";
	// std::cout << std::endl;

	std::string c;
	getline(std::cin, c);
	for (int i = 1; i <= m; i++) {
		getline(std::cin, c);
		// std::cout << c << std::endl;
		int point = 0;
		if (c.find("root") < c.size()) {
			int a = read(c, point);
			// std::cout << a << std::endl;
			if (ini[a] == 1) ans.push_back('T');
			else ans.push_back('F');
		}
		else if (c.find("siblings") < c.size()) {
			int a = read(c, point);
			point += 5;
			int b = read(c, point);
			// std::cout << a << " " << b << std::endl;
			int ql = 0, qr = 0;
			for (int i = 20; i >= 0; i--) {
				if ((1 << i) < ini[a]) {
					ql = (1 << i);
					qr = (1 << (i + 1)) - 1;
					break;
				}
			}
			if (ini[b] <= qr && ini[b] >= ql) ans.push_back('T');
			else ans.push_back('F');
		}
		else if (c.find("parent") < c.size()) {
			int a = read(c, point);
			point += 18;
			int b = read(c, point);
			// std::cout << a << " " << b << std::endl;
			int tt = 0;
			int ib = ini[b], ia = ini[a];
			while (ib) {
				if (ib == ia) {
					tt = 1;
					break;
				}
				ib /= 2;
			}
			if (tt) ans.push_back('T');
			else ans.push_back('F');
		}
		else {
			int a = read(c, point);
			point += 15;
			int b = read(c, point);
			// std::cout << a << " " << b << std::endl;
			// std::cout << ini[a] << " " << ini[b] << std::endl;
			int tt = 0;
			std::swap(a, b);
			int ib = ini[b], ia = ini[a];
			while (ib) {
				if (ib == ia) {
					tt = 1;
					break;
				}
				ib /= 2;
			}
			if (tt) ans.push_back('T');
			else ans.push_back('F');
		}
	}
	std::cout << ans[0];
	for (int i = 1; i < (int)ans.size(); i++) {
		std::cout << std::endl << ans[i];
	}
	return 0;
}