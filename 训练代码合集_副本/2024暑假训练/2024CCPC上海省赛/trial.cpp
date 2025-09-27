#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
#define ll long long
int main() {
    srand(time(NULL));
    double all = 0, time = 100000;
    for (int i = 1; i <= time; i++) {
        std::vector<int> q;
        for (int j = 1; j <= 60; j++) {  // 随机一个长度为20的序列
            q.push_back(rand() % 2);
        }
        for (int j = 1; j + 2 < (int)q.size(); j++) {
            if (q[j] == 1 && q[j + 1] == 1 && q[j + 2] == 0) {
                all += j + 2;  // 看看长度为多少的时候第一次出现HHT，然后累加求平均
                break;
            }
        }
    }
    std::cout << all / time << std::endl;
    return 0;
}