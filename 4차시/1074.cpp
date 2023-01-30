#include <cmath>
#include <iostream>

using namespace std;
int n, r, c;
int ans;

void rec(int x, int y, int s) { // 한변의 길이 2^s
    if (s == 1) {
        int new_x = r - x;
        int new_y = c - y;
        if (new_x == 0 and new_y == 0) // 0
            ans += 0;
        if (new_x == 0 and new_y == 1) // 1
            ans += 1;
        if (new_x == 1 and new_y == 0) // 2
            ans += 2;
        if (new_x == 1 and new_y == 1) // 3
            ans += 3;
    } else {
        int new_size = pow(2, s - 1);
        int new_x = r - x;
        int new_y = c - y;
        if (new_x < new_size and new_y < new_size) // 0사분면
        {
            rec(x, y, s - 1);
        }
        if (new_x < new_size and new_y >= new_size) // 1사분면
        {
            ans += new_size * new_size * 1;
            rec(x, y + new_size, s - 1);
        }
        if (new_x >= new_size and new_y < new_size) // 2사분면
        {
            ans += new_size * new_size * 2;
            rec(x + new_size, y, s - 1);
        }
        if (new_x >= new_size and new_y >= new_size) // 3사분면
        {
            ans += new_size * new_size * 3;
            rec(x + new_size, y + new_size, s - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;
    rec(0, 0, n);
    cout << ans;
}