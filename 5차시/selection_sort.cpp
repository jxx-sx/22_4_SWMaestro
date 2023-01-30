#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> V;

void selection_sort() {

    for (int i = 0; i < 19; i++) { // 넣을 위치
        int index = -1;
        int tmp = 200;
        for (int j = i; j < 20; j++) {
            if (V[j] < tmp) {
                index = j;
                tmp = V[j];
            }
        }
        swap(V[i], V[index]);
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);

    for (int i = 20; i > 0; i--)
        V.push_back(dis(gen));

    // 정렬 전
    cout << "before sort" << endl;
    for (auto a : V)
        cout << a << ' ';
    cout << endl << endl;

    selection_sort();
    cout << "after sort" << endl;
    for (auto a : V)
        cout << a << ' ';
    cout << endl << endl;
}