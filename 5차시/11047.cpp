#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

bool abc(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        v.push_back(inp);
    }

    sort(v.begin(), v.end(), abc);
    
    for (auto a : v) {
        cnt += (k / a);
        k = k % a;
        if (k == 0)
            break;
    }
    cout << cnt;
}
