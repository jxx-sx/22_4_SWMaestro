#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[100000];
vector<int> v1(100000, 0); // 사용한 경우
// i번째 원소를 사용 -> 얘부터 시작 vs 앞에서부터 이어져온것
vector<int> v2(100000, 0); // 사용하지 않은 경우
// i-1번째 원소를 사용한 경우 중에서 큰 값
int ans = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    v1[0] = arr[0];
    v2[0] = 0;
    for (int i = 1; i < n; i++) {
        v1[i] = max(arr[i], v1[i - 1] + arr[i]);
        v2[i] = max(v1[i - 1], v2[i - 1]);
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, v1[i]);
        ans = max(ans, v2[i]);
    }
    cout << ans;
}
