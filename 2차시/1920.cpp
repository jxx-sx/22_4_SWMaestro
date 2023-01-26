#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> V;
    int n, inp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        V.push_back(inp);
    }

    sort(V.begin(), V.end()); // 정렬
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> inp;
        if (binary_search(V.begin(), V.end(), inp)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}