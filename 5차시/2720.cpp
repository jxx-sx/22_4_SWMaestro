#include <iostream>

using namespace std;

void solve(int c) {
    int arr[4];
    arr[0] = c / 25;
    c = c - arr[0] * 25;
    arr[1] = c / 10;
    c = c - arr[1] * 10;
    arr[2] = c / 5;
    c = c - arr[2] * 5;
    arr[3] = c;
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << endl;
}

int main() {
    int T, C;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> C;
        solve(C);
    }
}
