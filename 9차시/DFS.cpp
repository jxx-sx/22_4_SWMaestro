#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[20];
bool is_visit[20];
int n;

void dfs(int now) {
    cout << now;          // 탐색을 통해 할 일
    is_visit[now] = true; // 방문 체크

    for (auto next : edges[now]) {   // 연결되어있는 노드들 중에
        if (is_visit[next] == false) // 다음 노드를 방문하지 않았다면 다음 노드를 방문
                                     // if (!is_visit[next])
            dfs(next);
    }
}

int main() {
    cin >> n;
    int s, e;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    dfs(1);
}

/*
1 2
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
10 11
*/
