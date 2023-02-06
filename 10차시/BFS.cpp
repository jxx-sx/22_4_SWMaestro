#include <iostream>
#include <queue>
#include <vector>

using namespace std;
queue<int> q; // 방문할 노드가 순서대로 저장됨
queue<int> q_distance;
vector<int> edges[1001];
bool is_visit[1001];
int n, m;

void bfs(int start_Node) {
    // 시작 전 준비
    q.push(start_Node); // 시작 노드 번호
    q_distance.push(0); // 시작 노드 거리 = 0
    is_visit[start_Node] = true;
    // bfs 수행
    int cur; // 현재 탐색하는 노드 번호
    int cur_distance;
    while (!q.empty()) {
        cur = q.front();
        cur_distance = q_distance.front();
        q.pop();
        q_distance.pop();
        // 인접한 노드를 큐에 추가
        for (auto next : edges[cur]) {
            if (!is_visit[next]) {
                q.push(next);                      // 다음 노드 추가
                q_distance.push(cur_distance + 1); // 다음 노드 거리 = 현재 노드 거리 + 1
                is_visit[next] = true;
            }
        }

        // 현재 노드에 대해서 할일
        cout << cur << ' ' << cur_distance << endl;
    }
}

int main() {
    cin >> n >> m;
    int s, e;
    while (m--) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    bfs(4);
}

// 6 7
// 1 2
// 1 3
// 2 3
// 2 4
// 2 5
// 3 5
// 3 6