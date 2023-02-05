#include <iostream>

using namespace std;

struct Node {
    char nodeData;
    int leftChildIndex;
    int rightChildIndex;
    //-1 : 자손 없음, 0~25
};

Node tree[26];
int n;

void preorder(int x) {
    cout << tree[x].nodeData; // 본인에 대한 탐색
    if (tree[x].leftChildIndex != -1) {
        preorder(tree[x].leftChildIndex);
    }
    if (tree[x].rightChildIndex != -1) {
        preorder(tree[x].rightChildIndex);
    }
}

void inorder(int x) { // 중위 순회
    if (tree[x].leftChildIndex != -1) {
        inorder(tree[x].leftChildIndex);
    }

    cout << tree[x].nodeData; // 본인에 대한 탐색

    if (tree[x].rightChildIndex != -1) {
        inorder(tree[x].rightChildIndex);
    }
}

void postorder(int x) {
    if (tree[x].leftChildIndex != -1) {
        postorder(tree[x].leftChildIndex);
    }
    if (tree[x].rightChildIndex != -1) {
        postorder(tree[x].rightChildIndex);
    }
    cout << tree[x].nodeData; // 본인에 대한 탐색
}

int main() {
    for (int i = 0; i < 26; i++) {
        tree[i].leftChildIndex = tree[i].rightChildIndex = -1;
    }

    cin >> n;
    char a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        tree[i].nodeData = a;
        if (b != '.') {
            tree[i].leftChildIndex = b - 'A';
        }
        if (c != '.') {
            tree[i].rightChildIndex = c - 'A';
        }
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}