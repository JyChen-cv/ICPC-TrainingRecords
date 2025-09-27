#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

const int N = 3e5;
int atc[N + 2], def[N + 2], l[N + 2], r[N + 2], tag[N + 2];

void remove(int x) {
	r[l[x]] = r[x];
	l[r[x]] = l[x];
}

bool check(int x)
{
	if (atc[l[x]] + atc[r[x]] > def[x]) return 1;
	else return 0;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			l[i] = i - 1;
			r[i] = i + 1;
			tag[i] = 0;
		}
		for (int i = 1; i <= n; i++) std::cin >> atc[i];
		for (int i = 1; i <= n; i++) std::cin >> def[i];
		atc[n + 1] = 0;
		def[n + 1] = 0x3f3f3f3f;
		atc[0] = 0;
		def[0] = 0x3f3f3f3f;

		std::queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (check(i)) {
				q.push(i);
				tag[i] = 1;
				// std::cout << i << std::endl;
			}
		}
		std::cout << q.size() << " ";
		n--;
		while (n--) {
			std::queue<int> q1;
			while (q.size()) {
				int x = q.front();
				q1.push(l[x]), q1.push(r[x]);
				remove(x);
				q.pop();
				// std::cout << x << std::endl;
			}
			// std::cout << q1.size() << "%";
			while (q1.size()) {
				int x = q1.front();
				if (!tag[x] && check(x)) {
					q.push(x);
					tag[x] = 1; // 永远是加入的时候标记，不是退出的时候标记
				}
				// std::cout<<x<<" ";
				q1.pop();
			}
			std::cout << q.size() << " ";
		}
		// for (int i = 1; i <= nn; i++) {
		// 	std::cout << tag[i] << " ";
		// }
		// puts("");
		puts("");
	}
	return 0;
}