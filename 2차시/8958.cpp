#include <iostream>
#include <string>

using namespace std;

int main() {
    int tc;
    int tmp = 0, ans = 0;
    string st;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> st;
        tmp = 0;
        ans = 0;
        for (int j = 0; j < st.size(); j++) {
            if (st[j] == 'O') {
                tmp++;
            } else {
                tmp = 0;
            }
            // ans += tmp;
            ans = ans + tmp;
        }
        cout << ans << endl;
    }
}
