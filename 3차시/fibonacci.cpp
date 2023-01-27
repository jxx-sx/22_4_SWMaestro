#include <iostream>

using namespace std;
int cnt = 0;

int arr[11];

int fibo(int x) {
    cnt++;
    if (arr[x] != -1)
        return arr[x];
    if (x == 0) {
        arr[x] = 0;
        return 0;
    }
    if (x == 1) {
        arr[x] = 1;
        return 1;
    }
    return (arr[x] = fibo(x - 1) + fibo(x - 2));
}

int fibo2(int x) {
    cnt++;
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return fibo2(x - 1) + fibo2(x - 2);
}

int main() {
    for (int i = 0; i < 11; i++)
        arr[i] = -1;
    int x;
    cin >> x;
    cout << fibo2(x) << ' ' << cnt;
}