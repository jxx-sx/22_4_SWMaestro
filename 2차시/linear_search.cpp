#include <iostream>
#include <random>

using namespace std;
int arr[20];

int find_num(int x) {
    for (int i = 0; i < 20; i++)
        if (arr[i] == x) // 값이 존재하는 경우
            return i;
    // 값이 존재하지 않는 경우
    return -1;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    int x;

    for (int i = 0; i < 20; i++) {
        arr[i] = dis(gen);
        cout << arr[i] << ' ';
    }
    cout << endl;

    cin >> x;
    cout << find_num(x) << endl;
}