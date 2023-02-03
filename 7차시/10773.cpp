#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    int k, input, sum = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> input;
        if (input == 0) {
            st.pop();
        } else {
            st.push(input);
        }
    }
    // int st_size = st.size();
    // for(int i = 0; i < st_size; i++)
    // while(st.size())
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}