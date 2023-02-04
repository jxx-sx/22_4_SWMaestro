#include <iostream>
#include <vector>
#define MAX_SIZE 10000

using namespace std;

struct Node {
    char node_data;
    int left_child;  // 배열의 인덱스
    int right_child; // 배열의 인덱스
    //-1은 자식 없음, 그 외는 인덱스가 가르키는 노드가 자손을 가르킴
};
// 문제에서 최대 10000개의 노드가 사용된다
Node tree[MAX_SIZE];

void order(int x) {

    // 전위 순회
    cout << tree[x].node_data << endl;
    // 왼쪽 서브트리에 대해서 재귀적 순회
    if (tree[x].left_child != -1) {
        order(tree[x].left_child);
    }

    // 중위 순회
    // cout << tree[x].node_data << endl;

    // 오른쪽 서브트리에 대해서 재귀적 순회
    if (tree[x].right_child != -1) {
        order(tree[x].right_child);
    }

    // 후위 순회
    // cout << tree[x].node_data << endl;
}

int main() {
    // 트리의 초기화 처음 설정
    int tree_size, edges_size;
    cin >> tree_size >> edges_size;
    // 값 초기화
    for (int i = 0; i < tree_size; i++) {
        // 데이터 = 알파벳
        tree[i].node_data = 'A' + i;
        // 초기 자손 없음 -> -1로 설정
        tree[i].left_child = -1;
        tree[i].right_child = -1;
    }

    // 부모와 자손의 관계를 이어줌
    char parent, child;
    for (int i = 0; i < edges_size; i++) {
        // 부모와 자손의 입력
        cin >> parent >> child;
        // 왼쪽 자손부터 채움 -> 왼쪽 자손이 비어있으면 왼쪽 자손부터 채움
        if (tree[parent - 'A'].left_child == -1)
            tree[parent - 'A'].left_child = child - 'A';
        // 왼쪽 자손이 차있으면(else) -> 오른쪽 자손을 채움
        else
            tree[parent - 'A'].right_child = child - 'A';
    }

    // 순회의 시작-> 루트 노드부터 -> 0번 노드
    order(0);
}
/*
입력 예시
9
8
A B
A C
B D
B E
D H
D I
C F
C G
*/