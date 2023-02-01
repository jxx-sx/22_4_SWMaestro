#include <iostream>

using namespace std;
int n;
int arr[1001]; // arr[i] n*i칸을 채우는 경우의 수

int main() {
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
// 가로로 이루어진 경우 -> 끝에 2칸을 차지 
//-> i-2칸의 경우에 가로로 블럭 추가 = i-2의 경우의 수
// 끝에 세로로 붙이는 경우 -> 끝에 1칸을 차지
//-> i-1칸의 경우에 세로로 블럭 추가 = i-1의 경우의 수
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    cout << arr[n];
}
//11727번