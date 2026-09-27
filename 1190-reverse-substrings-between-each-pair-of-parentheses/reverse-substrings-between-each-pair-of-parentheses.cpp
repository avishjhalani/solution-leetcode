class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) {
            if (c != ')')
                st.push(c);

            else {
                string curr = "";
                while (st.top() != '(') {
                    curr += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : curr) {
                    st.push(c);
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};