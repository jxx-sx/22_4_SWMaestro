#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);

    vector<int> V;
    for (int i = 20; i > 0; i--)
        V.push_back(dis(gen));

    // 정렬 전
    cout << "before sort" << endl;
    for (auto a : V)
        cout << a << ' ';
    cout << endl << endl;

    // 오름차순 정렬
    sort(V.begin(), V.end());

    cout << "ascending sort" << endl;
    for (auto a : V)
        cout << a << ' ';
    cout << endl << endl;

    // 내림차순 정렬
    sort(V.begin(), V.end(), greater());

    cout << "descending sort" << endl;
    for (auto a : V)
        cout << a << ' ';
    cout << endl;
}