#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q; // 방문할 노드가 순서대로 저장됨
vector<int> edges[1001];
bool is_visit_DFS[1001];
bool is_visit_BFS[1001];
int n, m, v;

void dfs(int now) {
    cout << now << ' ';       // 탐색을 통해 할 일
    is_visit_DFS[now] = true; // 방문 체크

    for (auto next : edges[now]) {       // 연결되어있는 노드들 중에
        if (is_visit_DFS[next] == false) // 다음 노드를 방문하지 않았다면 다음 노드를 방문
                                         // if (!is_visit[next])
            dfs(next);
    }
}

void bfs(int start_Node) {
    // 시작 전 준비
    q.push(start_Node); // 시작 노드 번호
    is_visit_BFS[start_Node] = true;
    // bfs 수행
    int cur; // 현재 탐색하는 노드 번호
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        // 인접한 노드를 큐에 추가
        for (auto next : edges[cur]) {
            if (!is_visit_BFS[next]) {
                q.push(next); // 다음 노드 추가
                is_visit_BFS[next] = true;
            }
        }

        // 현재 노드에 대해서 할일
        cout << cur << ' ';
    }
}

int main() {
    cin >> n >> m >> v;
    int s, e;
    while (m--) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(v);
    cout << endl;
    bfs(v);
}