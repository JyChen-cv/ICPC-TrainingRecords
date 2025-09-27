#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


// 题意 :
// 给定 n 个序列 
// 每个序列中有 一些数
// 现在以任意顺序遍历这些序列 (即可以先遍历 序列 1 ,再遍历序列2 , 也可以先遍历 序列2 , 再遍历序列 1)
// 若前面访问的最大数严格小于当前数 , 则获得一分
// 问怎样使得分数最大 

// 数据 规模 n <= 2e5 , 各个序列总元素个数小于 2e5

int n;

void getOrder(vector<int>& nums, queue<int>& s) {
	int pre = INT_MIN;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > pre) {
			s.emplace(nums[i]);
			pre = nums[i];
		}
	}
}

void slove() {
	cin >> n;

	vector<int> index(n + 1);
	vector<vector<int>> data(n + 1);
	vector<int> mx(n + 1);

	unordered_map<int, int> val;
	val.reserve(10000);

	// 输入 
	for (int i = 1; i <= n; i++) {
		index[i] = i;
		int count;
		cin >> count;
		data[i].resize(count + 1);
		int temp = 0;

		// 输入每个序列 并预处理最大值 
		for (int j = 1; j <= count; j++) {
			cin >> data[i][j];
			if (data[i][j] > temp) {
				temp = data[i][j];
			}
		}
		mx[i] = temp;
	}

	// 按最大值排序
	sort(index.begin() + 1, index.end(), [&](int i, int j) {
		return mx[i] < mx[j];
		});

	vector<int> dp(n + 1); // 可以证明 , 当最大值不同的时候 , dp是单调递增的
	                       // 当最大值相同的时候 , 由于无法从相同最大值的元素转移过来 , 最后计算该最大值的最大答案即可 
						
	// 枚举可能有所贡献的每一个数()  
	// 从最大值比这个有贡献的元素小的元素中值最大转移来 
	// dp[i] = max(max{elem in nums[i] + dp[max(mx[i] < elem)]})
	// 有所贡献的数个数为 n , 对于每一个数进行一次二分查找 , 时间复杂度是 nlogn 
     

	// 每一次按顺序压栈
	queue<int> s;

	for (int i = 1; i <= n; i++) {
		getOrder(data[index[i]], s); // 获取序列中按从到小的顺序
		if (i == 1) { // 最开始无法转移 
			dp[i] = s.size();
			val[mx[index[1]]] = s.size();
			while (!s.empty()) {
				s.pop();
			}
			continue;
		}

		int res = s.size(); // 最大转移 , 前面一个不取的情况

		while (!s.empty()) {
			if (mx[index[1]] >= s.front()) {
				s.pop(); // 不存在合法转移 
				continue;
			}
			if (mx[index[i - 1]] < s.front()) {
				res = max(dp[i - 1] + (int)s.size(), res); // 当前可以从任意一个结点处转移过来 
				while (!s.empty()) {
					s.pop();
				}
				break;
			}

			// 二分查找 最大且满足转移规则的元素 
			auto it = lower_bound(index.begin() + 1, index.begin() + (i - 1), s.front(), [&](int i, int j) {
				return mx[i] < j;
				});

			it--;

			res = max(val[mx[index[*it]]] + (int)s.size(), res);
			s.pop();
		}

		// 更新 
		dp[i] = res;
		val[mx[index[i]]] = max(val[mx[index[i]]], res);
	}

	// 输出答案 
	// 其实 dp.back() 即是答案 
	int res = dp[1];
	for (int i = 2; i <= n; i++) {
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}