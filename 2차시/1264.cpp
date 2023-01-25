#include <iostream>
#include <string>

using namespace std;

int main() {
    string st = "";
    char charArr[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (st != "#") {
        int cnt = 0;
        getline(cin, st);
        if (st == "#")
            break;
        for (int i = 0; i < st.size(); i++) {
            for (int j = 0; j < 10; j++) {
                if (st[i] == charArr[j]) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
}
