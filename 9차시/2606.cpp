#include <iostream>
#include <vector>

using namespace std;
vector<int> edges[101];
bool is_visit[101];

void dfs(int now) {
    is_visit[now] = true;
    // code

    for (auto next : edges[now]) {
        if (is_visit[next] == false) {
            dfs(next);
        }
    }
}

int main() {
    int n, k; // n 노드(컴퓨터)의 개수, k 간선의 개수
    int s, e;
    cin >> n >> k;
    while (k--) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    dfs(1);

    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (is_visit[i])
            cnt++;

    cout << cnt;
}