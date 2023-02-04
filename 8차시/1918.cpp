#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 피연산자(숫자)가 들어오면 바로 출력한다.

// 연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 스택에서 빼고 자신을 스택에 담는다

// ‘(‘는 무조건 스택에 담는다

// ’)’가 나오면 스택에서 ‘(‘가 나오기 전까지 모든 연산자를 꺼낸다 그리고 ‘(‘를 없앤다.

stack<char> oper;
string str;

int priority(char o) {
    if (o == '+' or o == '-')
        return 1;
    if (o == '(')
        return 0;
    else //*, /
        return 2;
}

int main() {
    cin >> str; // 중위표기법
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] and str[i] <= 'Z') { // 숫자
            cout << str[i];
        } else if (str[i] == '(') {
            oper.push('(');
        } else if (str[i] == ')') {
            while (!oper.empty()) {
                if (oper.top() == '(') {
                    oper.pop();
                    break;
                } else {
                    cout << oper.top();
                    oper.pop();
                }
            }
        } else { // 연산자
            while (!oper.empty()) {
                if (priority(oper.top()) >= priority(str[i])) {
                    cout << oper.top();
                    oper.pop();
                } else {
                    break;
                }
            }
            oper.push(str[i]);
        }
    }
    
    while (!oper.empty()) {
        cout << oper.top();
        oper.pop();
    }
}