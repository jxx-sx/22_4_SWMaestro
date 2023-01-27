#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
int cnt;
int recursion(const char *s, int l, int r) {
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
    cnt = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        cout << isPalindrome(st.c_str()) << ' ' << cnt << '\n';
    }
}