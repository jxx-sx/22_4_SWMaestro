#include <iostream>

using namespace std;
int n;
int cost[1001][3];
// cost[i][j] i번째 집까지 칠했을 때, i번째 집이 j색상인경우 비용의 최솟값
// j 0 빨강 1 초록 2 파랑
int main() {
    int r, g, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r >> g >> b;
        // 빨간색을 칠하는 경우
        cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + r;
        // 초록색을 칠하는 경우
        cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + g;
        // 파란색을 칠하는 경우
        cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + b;
    }
    cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
}