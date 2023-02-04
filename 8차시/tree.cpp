#include <iostream>
#include <vector>

using namespace std;
vector<int> tmp_edges[10];

void order(int x) {
    
}

int main() {
    // 노드의 개수 : 10개 1, 2, 3, ... , 10
    // 간선
    //  1 2
    //  3 4

    // 저장하는 방식
    //  배열에 저장한다 -> 노드의 개수 n, n*n 배열 -> arr[i][j] = 1 -> i노드 ~ j노드까지 연결되어있다, 0-> 연결되어있지 않다
    //  벡터, 배열에 저장한다 -> 벡터를 노드의 개수만큼 배열로 1~10 1번 벡터: 1번 노드에서 이어진 노드들을 전부 기록

    // 배열에 저장하는 방식
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    // 간선의 갯수 : k개
    int k;
    int start, end;
    for (int i = 0; i < k; i++) {
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }

    // 벡터에 저장하는 방식
    int n;
    cin >> n;
    vector<int> edges[n];
    // 간선의 갯수 : k개
    int k;
    int parent, child; // 부모 자식
    for (int i = 0; i < k; i++) {
        cin >> parent >> child;
        edges[parent].push_back(child);
    }
}