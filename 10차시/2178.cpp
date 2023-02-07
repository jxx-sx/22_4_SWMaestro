#include <iostream>
#include <queue>
#include <string>

using namespace std;

int maze[100][100];
bool is_visit[100][100];
int n, m;
queue<int> x, y, maze_distance;

int main() {
    string input;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '1')
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }
    }

    // bfs 준비
    x.push(0);
    y.push(0);
    maze_distance.push(1);
    is_visit[0][0] = true;
    int cur_x, cur_y, cur_distance;
    while (!x.empty()) {
        cur_x = x.front();
        x.pop();
        cur_y = y.front();
        y.pop();
        cur_distance = maze_distance.front();
        maze_distance.pop();

        // 답을 구함 == 미로의 끝에 도달
        if (cur_x == m - 1 and cur_y == n - 1) {
            cout << cur_distance;
            break;
        }
        //[y][x]
        // 0 <= y < n
        // 0 <= x < m
        // 인접한 노드 추가
        if (cur_x - 1 >= 0) {
            if (!is_visit[cur_y][cur_x - 1] and maze[cur_y][cur_x - 1] == 1) {
                x.push(cur_x - 1);
                y.push(cur_y);
                maze_distance.push(cur_distance + 1);
            }
        }
        if (cur_x + 1 < m) {
            if (!is_visit[cur_y][cur_x + 1] and maze[cur_y][cur_x + 1] == 1) {
                x.push(cur_x + 1);
                y.push(cur_y);
                maze_distance.push(cur_distance + 1);
            }
        }

        if (cur_y - 1 >= 0) {
            if (!is_visit[cur_y - 1][cur_x] and maze[cur_y - 1][cur_x] == 1) {
                x.push(cur_x);
                y.push(cur_y - 1);
                maze_distance.push(cur_distance + 1);
            }
        }

        if (cur_y + 1 < n) {
            if (!is_visit[cur_y + 1][cur_x] and maze[cur_y + 1][cur_x] == 1) {
                x.push(cur_x);
                y.push(cur_y + 1);
                maze_distance.push(cur_distance + 1);
            }
        }
    }
}