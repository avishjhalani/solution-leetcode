class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (abs(ast) > st.top()) {
                    st.pop();  // top asteroid explodes, continue checking
                } else if (abs(ast) == st.top()) {
                    st.pop();  // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // current asteroid explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push(ast);
            }
        }

        // Convert stack to vector (in correct order)
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
