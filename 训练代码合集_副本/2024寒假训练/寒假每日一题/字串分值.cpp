#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<long long> sz[30];

int main()
{
	std::string mapp;
	std::cin >> mapp;
	for (int i = 1; i <= 26; i++) sz[i].push_back(0);
	for (int i = 0; i < (int)mapp.size(); i++) {
		sz[mapp[i] - 'a' + 1].push_back(i + 1);
	}
	for (int i = 1; i <= 26; i++) sz[i].push_back((int)mapp.size() + 1);

	long long ans = 0;
	for (int i = 1; i <= 26; i++) {
		long long ls = 0;
		for (int j = 1; j < (int)sz[i].size() - 1; j++) {
			ls += (sz[i][j] - sz[i][j - 1]) * (sz[i][j + 1] - sz[i][j]);
		}
		ans += ls;
	}
	std::cout << ans << std::endl;

	return 0;
}