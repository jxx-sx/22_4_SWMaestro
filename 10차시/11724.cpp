#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> edges[1001];
bool is_visit[1001]; // false
int cnt = 0;

void dfs(int now) {
    is_visit[now] = true;

    for (auto next : edges[now]) {
        if (!is_visit[next]) {
            dfs(next);
        }
    }
}

/*void dfs(int now) {
    if(is_visit[now]){
        return;
    }

    is_visit[now] = true;

    for (auto next : edges[now]) {
        dfs(next);
    }
}*/

int main() {
    cin >> n >> m;
    int s, e;
    while (m--) {
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        if (!is_visit[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;
}