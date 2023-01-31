#include <iostream>
#include <string>

using namespace std;

int main() {
    int seat_cnt, s = 0, l = 0;
    string seat;
    cin >> seat_cnt >> seat;
    for (int i = 0; i < seat.size(); i++) {
        if (seat[i] == 'S')
            s++;
        else
            l++;
    }
    if (l == 0) {
        cout << seat_cnt;
    } else {
        l /= 2;
        cout << s + l + 1;
    }
}
