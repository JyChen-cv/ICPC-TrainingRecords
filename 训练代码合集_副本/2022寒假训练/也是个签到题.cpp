#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

std::string mapp;

long long main() {
	long long t;
	std::cin >> t;
	while (t--) {
		mapp.clear();

		std::cin >> mapp;
		long long tag1 = 0;
		long long ans = 1;
		for (long long i = 0; i < (long long)mapp.size(); i++) {
//			std::cout << tag1 << std::endl;
			if (mapp[i] == 'M') {
				if (tag1 == 0) {
					tag1 = 1;
				} else {
					if (tag1 != 1) {
						ans = 0;
						break;
					} else
						tag1 = 0;
				}
			} else if (mapp[i] == 'G') {
				if (tag1 == 0) {
					tag1 = 2;
				} else {
					if (tag1 != 2) {
						ans = 0;
						break;
					} else {
						tag1 = 0;
					}
				}
			} else if (mapp[i] == 'K') {
				if (tag1 == 0) {
					tag1 = 3;
				} else {
					if (tag1 != 3) {
						ans = 0;
						break;
					} else {
						tag1 = 0;
					}
				}
			}
		}
		if (tag1 == 0)
			std::cout << ans << std::endl;
		else
			std::cout << 0 << std::endl;
	}

	return 0;
}