#include <iostream>
#include <vector>

using namespace std;

int arr[50][50];
int m, n, k;
void dfs(int x, int y) {
    arr[x][y] = 0;

    if (x + 1 < m)
        if (arr[x + 1][y] == 1)
            dfs(x + 1, y);

    if (x - 1 >= 0)
        if (arr[x - 1][y] == 1)
            dfs(x - 1, y);

    if (y + 1 < n)
        if (arr[x][y + 1] == 1)
            dfs(x, y + 1);

    if (y - 1 >= 0)
        if (arr[x][y - 1] == 1)
            dfs(x, y - 1);
}

int main() {
    int tc, x, y;
    cin >> tc;
    while (tc--) {
        cin >> m >> n >> k;
        while (k--) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == 1) {
                    cnt++;
                    dfs(i, j);
                }
        cout << cnt << '\n';
    }
}