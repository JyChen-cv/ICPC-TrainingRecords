#include <cstdio>
#include <iostream>
using namespace std;
bool q[1];
bool w[1003];
int main() {
    int a, real, num;
    scanf("%d", &a);
    real = a;
    while (real > 2) {
        if (q[0] == false) {
            num = 0;
            for (int i = 1; i <= a; i++) {
                if (w[i] == false) {
                    num = num + 1;
                    if (num % 3 == 0) {
                        w[i] = true;
                        real--;
                    }
                }
            }
        } else {
            num = 0;
            for (int i = a; i >= 1; i--) {
                if (w[i] == false) {
                    num = num + 1;
                    if (num % 3 == 0) {
                        w[i] = true;
                        real--;
                    }
                }
            }
        }
        q[0] = !q[0];
        // cout<<endl;
    }
    if (q[0] == 0) {
        for (int i = 1; i <= a; i++)
            if (w[i] == 0) {
                cout << i;
                break;
            }
    } else {
        for (int i = a; i >= 1; i--)
            if (w[i] == 0) {
                cout << i;
                break;
            }
    }
    return 0;
}