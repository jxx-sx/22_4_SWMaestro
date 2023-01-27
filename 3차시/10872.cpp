#include <iostream>

using namespace std;

int fac(int x) {
    if (x == 0)
        return 1;
    return fac(x - 1) * x;
}

int main() {

    int x;
    cin >> x;
    cout << fac(x);
}