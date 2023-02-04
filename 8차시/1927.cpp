#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> pq1; // 커스텀 or 정수인 경우 부호를 변환해서 넣으면
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 0) {
            // 출력
            if (pq2.empty()) {
                cout << 0 << endl;
            } else {
                // cout << -pq1.top() << endl;
                //  pq1.pop();

                cout << pq2.top() << endl;
                pq2.pop();
            }
        } else {
            // push
            // pq1.push(-input);
            pq2.push(input);
        }
    }
}

