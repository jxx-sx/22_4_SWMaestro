#include <iostream>

using namespace std;

int arr[2187][2187];
int ans[3];

void recursion(int x, int y, int s) { // arr[x][y]~ arr[x+s-1][y+s-1]
    // 문제를 해결할 수 있는지 = 모두 같은 색의 종이인가
    bool check = true;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (arr[x + i][y + j] != arr[x][y]) {
                check = false;
                break;
            }
            if (!check)
                break;
        }
    }
    // 해결할 수 있다면 정복 = 하나의 종이
    if (check)
        ans[arr[x][y] + 1]++;
    // 해결할 수 없다면 분할 = 여러개의 종이이므로 쪼갠다
    else {
        int new_size = s / 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                recursion(x + i * new_size, y + j * new_size, new_size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    recursion(0, 0, n);

    cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
}