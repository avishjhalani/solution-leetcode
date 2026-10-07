class Solution {
public:
    unordered_set<string> st;
    int n;

    void solve(int idx, int count, string &curr, string &s, int &maxlen) {

        if(count < 0)
            return;

        if(idx == n) {

            if(count == 0) {

                if(curr.size() > maxlen) {
                    st.clear();
                    maxlen = curr.size();
                }

                if(curr.size() == maxlen) {
                    st.insert(curr);
                }
            }

            return;
        }

        // Normal character
        if(s[idx] != '(' && s[idx] != ')') {

            curr.push_back(s[idx]);

            solve(idx + 1, count, curr, s, maxlen);

            curr.pop_back();

            return;
        }

        // Take the parenthesis
        curr.push_back(s[idx]);

        solve(
            idx + 1,
            count + (s[idx] == '(' ? 1 : -1),
            curr,
            s,
            maxlen
        );

        curr.pop_back();

        // Don't take the parenthesis
        solve(idx + 1, count, curr, s, maxlen);
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();

        string curr = "";

        int maxlen = 0;

        solve(0, 0, curr, s, maxlen);

        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};