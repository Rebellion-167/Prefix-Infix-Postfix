#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s) {
    stack<string> st;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(isalnum(s[i]))
            st.push(string(1, s[i]));
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = s[i] + t2 + t1;
            st.push(con);
        }
    }
    return st.top();
}

int main() {
    string s = "abc*+d-";
    string ans = postfixToPrefix(s);
    cout << ans << '\n';
    return 0;
}

// tc - O(n)
// sc - O(n)