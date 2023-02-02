#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int queue_data[1000];
int front = 0; // 나갈 데이터의 위치
int back = 0;  // 데이터가 들어올 위치

bool queue_empty() { return front == back; }

void queue_push(int x) {
    if (back == 1000) {
        cout << "full queue";
        return;
    }
    queue_data[back] = x;
    back++;
}

int queue_front() {
    if (queue_empty()) {
        cout << "Error";
        return -1;
    }
    return queue_data[front];
}

int queue_back() {
    if (queue_empty()) {
        cout << "Error";
        return -1;
    }
    return queue_data[back - 1];
}

void queue_pop() {
    if (!queue_empty()) {
        front++;
    }
}

int queue_size() { return back - front; }

int main() {
    for (int i = 1; i < 10; i++)
        q.push(i); // 데이터 추가
    q.front();     // 처음에 넣은 데이터 반환
    q.back();      // 마지막에 넣은 데이터 반환
    q.pop();       // 제거
    q.size();      // 크기
    q.empty();     // 비어있는지
}