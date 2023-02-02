#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;                            // 데이터 자체가 우선순위 -> 숫자가 큰게 먼저 나와
priority_queue<int, vector<int>, greater<int>> pq; // 데이터 자체가 우선순위 -> 숫자가 큰게 먼저 나와

int main() {
    for (int i = 1; i < 10; i++)
        pq.push(-i);
    pq.top();
    pq.pop();
    pq.size();
    pq.empty();
}