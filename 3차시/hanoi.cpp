#include <iostream>

using namespace std;

int hanoi(int x) {
    if (x == 1)
        return 1;
    return 2 * hanoi(x - 1) + 1;
    // return hanoi(x - 1) + 1 + hanoi(x - 1);
}

int main() {
    int x;
    cin >> x;
    cout << hanoi(x);
}