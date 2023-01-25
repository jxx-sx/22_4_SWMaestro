#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);

    int arr_size = 20;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
        arr[i] = dis(gen);

    // 정렬 전
    cout << "before sort" << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << ' ';
    cout << endl;

    // 오름차순 정렬
    sort(arr, arr + arr_size);

    cout << "ascending sort" << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << ' ';
    cout << endl;

    // 내림차순 정렬
    sort(arr, arr + arr_size, greater());

    cout << "descending sort" << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}