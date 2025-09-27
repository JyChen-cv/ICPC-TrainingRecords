// 对拍程序，命名为check.cpp
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int t = 1000;
    while (t--) {
        // system("cd /Users/chenjiayou/Desktop/Cpp/tpai/");
        // system("/Users/chenjiayou/Desktop/2024寒假训练/tpai/data>/Users/chenjiayou/Desktop/2024寒假训练/tpai/data.txt");
        system("time /Users/chenjiayou/Desktop/2024寒假训练/tpai/my</Users/chenjiayou/Desktop/2024寒假训练/tpai/data.txt>/Users/chenjiayou/Desktop/2024寒假训练/tpai/my.txt");
        system("time /Users/chenjiayou/Desktop/2024寒假训练/tpai/std</Users/chenjiayou/Desktop/2024寒假训练/tpai/data.txt>/Users/chenjiayou/Desktop/2024寒假训练/tpai/std.txt");
        if (system("diff /Users/chenjiayou/Desktop/2024寒假训练/tpai/std.txt /Users/chenjiayou/Desktop/2024寒假训练/tpai/my.txt")) {
            cout << "error" << endl;
            break;
        } else
            cout << "no error" << endl;
    }
    return 0;
}