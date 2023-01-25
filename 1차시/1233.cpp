#include <iostream>

using namespace std;

int main() {
    int s1, s2, s3;
    int max_cnt = 0;
    cin >> s1 >> s2 >> s3;
    int arr[s1 + s2 + s3 + 1]; // 1번째 주사위 i, 2번째 j, 3번째 k
    // 초기화
    for (int i = 0; i < s1 + s2 + s3 + 1; i++)
        arr[i] = 0; // 배열의 [인덱스] 인덱스 = 눈의합

    // 브루트 포스
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                arr[i + j + k]++;
                // max_cnt = max_cnt < arr[i + j + k] ? arr[i + j + k] : max_cnt;
                max_cnt = max(arr[i + j + k], max_cnt);
            }
        }
    }
    for (int i = 0; i < s1 + s2 + s3 + 1; i++)
        if (arr[i] == max_cnt) {
            cout << i;
            break;
        }
}