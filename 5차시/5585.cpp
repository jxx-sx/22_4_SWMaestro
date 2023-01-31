#include <iostream>

using namespace std;

void solve(int c) {
    int cnt = 0;
    cnt += c / 500;
    c %= 500;
    cnt += c / 100;
    c %= 100;
    cnt += c / 50;
    c %= 50;
    cnt += c / 10;
    c %= 10;
    cnt += c / 5;
    c %= 5;
    cnt += c;
    cout << cnt;
}

int main() {
    int C;
    cin >> C;
    solve(1000 - C);
}
