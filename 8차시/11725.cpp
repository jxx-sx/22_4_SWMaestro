#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    int s, e;
    vector<int> edges[n + 1];
    bool is_visit[n + 1];
    int parent[n + 1];
    queue<int> q; // 부모를 찾은 노드들 번호

    for (int i = 0; i < n + 1; i++) {
        is_visit[i] = false; // 방문하지 않았다
        parent[i] = -1;      // 아직 부모가 누군지 모른다
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    
    q.push(1);
    is_visit[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto a : edges[cur]) {
            if (is_visit[a]) { // 먼저 방문된 노드 -> 부모가 누구인지 알고 있음
                // 할일 없음
                // 부모인 경우
            } else { // 지금 처음 방문함 -> 현재 cur노드가 부모가 됨
                parent[a] = cur;
                is_visit[a] = true; // 방문을 했다->부모가 누구인지 알게되었다
                q.push(a);
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << parent[i] << endl;
}