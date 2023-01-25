#include <iostream>

using namespace std;

int main() {
    int T;
    int n, m;
    int a, b;
    int cnt;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> m;
        cnt = 0;
        for (a = 1; a < n; a++) {
            for (b = a + 1; b < n; b++) {
                if ((a * a + b * b + m) % (a * b) == 0) {
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }
}