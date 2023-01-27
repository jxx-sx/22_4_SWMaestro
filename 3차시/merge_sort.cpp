#include <iostream>
#include <random>
#include <vector>

using namespace std;
vector<int> v;

vector<int> merge_sort(int s, int e, int depth) {
    if (s == e)
        return vector<int>(1, v[s]);
    vector<int> ret;
    vector<int> left_child = merge_sort(s, (s + e) / 2, depth + 1);
    vector<int> right_child = merge_sort((s + e) / 2 + 1, e, depth + 1);
    int left_i = 0;
    int right_i = 0;
    while (left_i < left_child.size() and right_i < right_child.size()) {
        if (left_child[left_i] < right_child[right_i])
            ret.push_back(left_child[left_i++]);
        else
            ret.push_back(right_child[right_i++]);
    }
    if (left_i != left_child.size()) {
        for (; left_i < left_child.size(); left_i++)
            ret.push_back(left_child[left_i]);
    }

    if (right_i != right_child.size()) {
        for (; right_i < right_child.size(); right_i++)
            ret.push_back(right_child[right_i]);
    }
    cout << "depth : " << depth << endl;
    for (auto a : ret) {
        cout << a << ' ';
    }
    cout << endl;
    return ret;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    for (int i = 0; i < 16; i++) {
        v.push_back(dis(gen));
    }

    for (auto a : v)
        cout << a << ' ';
    cout << endl;

    for (auto a : merge_sort(0, v.size() - 1, 1))
        cout << a << ' ';
}
