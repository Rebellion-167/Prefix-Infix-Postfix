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

string reverseExpression(string s) {
    int l = s.length();

    reverse(s.begin(), s.end());

    for(int i = 0; i < l; i++) {
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }

    return s;
}

string infixToPrefix(string s) {
    s = reverseExpression(s);

    stack<char> st;
    string ans = "";
    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(isalnum(s[i]))
            ans += s[i];
        else if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')') {
            while(!st.empty() and st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if(s[i] == '^') {
                while(!st.empty() and getPriority(s[i]) <= getPriority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            } else {
                while(!st.empty() and getPriority(s[i]) < getPriority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    ans = reverseExpression(ans);
    return ans;
}

int main() {
    string s = "x+y*z/w+u";
    string ans = infixToPrefix(s);
    cout << ans << endl;
    return 0;
}