#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    stack<string> st;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(isalnum(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string con = "(" + op1 + s[i] + op2 + ")";
            st.push(con);
        }
    }

    string ans = st.top();
    st.pop();
    return ans;
}

int main() {
    string s = "ab+c*";
    string ans = postfixToInfix(s);
    cout << ans << '\n';
    return 0;
}