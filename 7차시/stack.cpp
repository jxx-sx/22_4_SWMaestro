#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int stack_data[1000];
int top = 0; // 데이터가 들어갈 위치 == 데이터의 마지막 위치 + 1

void stack_push(int x) {
    stack_data[top] = x;
    top = top + 1;
}

int stack_top() {
    if (top == 0) {
        cout << "Error";
        return -1;
    }
    return stack_data[top - 1];
}

void stack_pop() {
    if (top != 0)
        top -= 1;
}

int stack_size() { return top; }

bool stack_empty() { return top == 0; }

int main() {
    for (int i = 1; i < 10; i++)
        st.push(i);
    st.top();
    st.pop();
    st.size();
    st.empty();
}