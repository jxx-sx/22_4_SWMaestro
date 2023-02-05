#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[20]; 
bool is_visit[20];
int n;

void dfs(int now) {
    cout << now;
    is_visit[now] = true;

    for (auto next : edges[now]) {
        if (is_visit[next] == false)
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
