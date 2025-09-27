#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

std::map<int, int> is;
std::vector<int> q;
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		is[a] = i;
		q.push_back(a);
	}
	std::sort(q.begin(), q.end());
	n--;
	while (n--) {

	}
	return 0;
}