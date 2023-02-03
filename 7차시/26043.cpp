#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<int> student, menu;

    vector<int> groupA, groupB, groupC;
    int n, mode, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mode;
        if (mode == 1) {
            cin >> a >> b;
            student.push(a);
            menu.push(b);
        } else { // mode == 2
            cin >> b;
            if (b == menu.front())
                groupA.push_back(student.front());
            else {
                groupB.push_back(student.front());
            }
            student.pop();
            menu.pop();
        }
    }

    while (!student.empty()) {
        groupC.push_back(student.front());
        student.pop();
        menu.pop();
    }

    sort(groupA.begin(), groupA.end());
    sort(groupB.begin(), groupB.end());
    sort(groupC.begin(), groupC.end());

    if (groupA.size() == 0) {
        cout << "None\n";
    } else {
        for (auto a : groupA)
            cout << a << ' ';
        cout << endl;
    }

    if (groupB.size() == 0) {
        cout << "None\n";
    } else {
        for (auto a : groupB)
            cout << a << ' ';
        cout << endl;
    }

    if (groupC.size() == 0) {
        cout << "None\n";
    } else {
        for (auto a : groupC)
            cout << a << ' ';
        cout << endl;
    }
}