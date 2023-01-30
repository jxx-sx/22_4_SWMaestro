#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree_height;
int n, m, ans = 0;

long long get_tree(int height) {
    long long ret = 0;
    for (auto a : tree_height) {
        if (height < a)
            ret += a - height;
    }

    return ret;
}

void find_height() {
    int lo = 0;
    int hi = tree_height.back();
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (get_tree(mid) < m) {
            hi = mid - 1;
        } else {
            ans = max(mid, ans);
            lo = mid + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        tree_height.push_back(inp);
    }
    sort(tree_height.begin(), tree_height.end());
    find_height();
    cout << ans;
}