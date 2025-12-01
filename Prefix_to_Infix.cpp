#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    stack<string> st;
    int n = s.length();

    for(int i = n - 1; i >= 0; i--) {
        if(isalnum(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = "(" + t1 + s[i] + t2 + ")";
            st.push(con);
        }
    }

    return st.top();
}

int main() {
    string s = "*+ab-cd";
    string ans = prefixToInfix(s);
    cout << ans << '\n';
    return 0;
}

// tc - O(n)
// sc - O(n)