class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else if (!temp.empty()) {
                reverse(temp.begin(), temp.end());
                if (!res.empty()) res += ' ';
                res += temp;
                temp.clear();
            }
        }
        
        // Add the first word (if exists)
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!res.empty()) res += ' ';
            res += temp;
        }
        
        return res;
    }
};
