#include <iostream>

using namespace std;
int n;
int arr[1001]; // arr[i] 2*i칸을 채우는 경우의 수

int main() {
    cin >> n;
    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007;
    }
    cout << arr[n];
}
// 11727번