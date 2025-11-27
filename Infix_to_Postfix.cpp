#include <bits/stdc++.h>
using namespace std;

int getPriority(char ch) {
    switch(ch) {
        case '^':
            return 3;
        
        case '*':
        case '/':
            return 2;
        
        case '+':
        case '-':
            return 1;

        default:
            return -1;
    }
}

string infixToPostfix(string s) {
    stack<char> st;
    string res = "";
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(isalnum(s[i])) {
            res.push_back(s[i]);
        } else if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() and st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() and getPriority(s[i]) <= getPriority(st.top())) {
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        if(st.top() != '(')
            res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main() {
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = infixToPostfix(s);
    cout << ans << '\n';
    return 0;
}