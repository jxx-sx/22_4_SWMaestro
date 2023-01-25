#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

int arr[20];

int find_num(int x) {
    int lo = 0, hi = 20;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);

    for (int i = 0; i < 20; i++)
        arr[i] = dis(gen);

    // 정렬
    sort(arr, arr + 20);
    for (int i = 0; i < 20; i++)
        cout << arr[i] << ' ';
    cout << endl;

    int x;
    cin >> x;
    cout << find_num(x) << endl;
}