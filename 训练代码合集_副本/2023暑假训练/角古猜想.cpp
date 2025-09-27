#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    while (a != 1) {
        cout << a;
        if (a % 2 == 1) {
            a = a * 3 + 1;
            cout << "*3+1=" << a << endl;
        } else {
            a = a / 2;
            cout << "/2=" << a << endl;
        }
    }
    cout << "End";
    return 0;
}